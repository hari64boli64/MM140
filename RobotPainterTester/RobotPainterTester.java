import java.awt.*;
import java.awt.geom.*;
import java.util.*;
import java.io.*;
import javax.imageio.*;
import java.util.List;
import java.util.ArrayList;
import java.awt.image.BufferedImage;

import com.topcoder.marathon.*;

public class RobotPainterTester extends MarathonAnimatedVis
{
  // Parameter ranges
  private static final int minN = 6, maxN = 30;         // grid size range
  private static final int minJC = 2, maxJC = 5;        // jump cost range
  private static final int minFC = 2, maxFC = 5;        // for cost range
  
  // Inputs
  private int N;                // grid size
  private int JC;               // cost of Move command
  private int FC;               // cost of For command

  // Constants
  private static final int Penalty=10;
  private static final int startR=0;
  private static final int startC=0;
  private static final int startDir=0;
  private static final int MinIter=2;           //minimum iterations in a FOR loop
  private static final int MaxIter=10;          //maximum iterations in a FOR loop
  private static final int MaxNesting=3;        //maximum number of for nestings
  private static final int[] dr={0,1,1,1,0,-1,-1,-1};     //8 neighbouring directions
  private static final int[] dc={1,1,0,-1,-1,-1,0,1};
  private static final float[] dv={1,0.707f,1,0.707f,1,0.707f,1,0.707f};  //multiplier used for drawing

  private static final String Left="L";           
  private static final String Right="R";
  private static final String PenUp="U";
  private static final String PenDown="D";
  private static final String Forward="F";
  private static final String Back="B";
  private static final String Jump="J";           
  private static final String ForStart="FOR";
  private static final String ForEnd="END";
  private static final String[] Moves={Left,Right,PenUp,PenDown,Forward,Back,Jump,ForStart,ForEnd};
  
  // State Control
  private boolean[][] grid;       //target grid
  private boolean[][] painted;    //grid painted by the robot
  // current state of the robot
  private int R;                  
  private int C;                
  private int Dir;
  private boolean isPenUp;
  private int Commands;
  // for visualisation
  private int Fors;
  private int Jumps;  
  private int CommandId;  
  private int Errors;
  private int Score;  


  protected void generate()
  {
    N = randomInt(minN, maxN);
    JC = randomInt(minJC, maxJC);
    FC = randomInt(minFC, maxFC);

    //Special cases
    if (seed == 1)
    {
      N = minN;
    }
    else if (seed == 2)
    {
      N = maxN;
    }

    //User defined parameters
    if (parameters.isDefined("N")) N = randomInt(parameters.getIntRange("N"), minN, maxN);
    if (parameters.isDefined("JC")) JC = randomInt(parameters.getIntRange("JC"), minJC, maxJC);
    if (parameters.isDefined("FC")) FC = randomInt(parameters.getIntRange("FC"), minFC, maxFC);
    
    grid = new boolean[N][N];
    painted = new boolean[N][N];    

    //generate a grid with at least N+1 painted cells
    for (int iter=0; true; iter++)
    {
      //generate random moves
      Move[] moves=generateMoves();
      
      //now play them and paint the grid
      playMoves(moves,grid,false);
      
      int count=0;
      for (int r=0; r<N; r++) for (int c=0; c<N; c++) if (grid[r][c]) count++;
      
      //System.out.println(iter+" "+count);
          
      if (count>=N*N*1/3 && count<=N*N*2/3)
      {
        //printMoves(moves);        //NOTE: uncomment this to see what program was used to generate the grid
        break;
      }
      
           
      for (int r=0; r<N; r++) for (int c=0; c<N; c++) grid[r][c]=false;     //reset grid
    }
    

    if (debug)
    {
      System.out.println("Grid size, N = " + N);
      System.out.println("Jump cost, JC = " + JC);
      System.out.println("For cost, FC = " + FC);
      System.out.println("Grid:");
      for (int row = 0; row < N; row++)
      {
        for (int col = 0; col < N; col++)
          System.err.print(grid[row][col] ? "#" : ".");
        System.out.println();
      }
    }
  }
  
  
  private void printMoves(Move[] moves)
  {
    int forCount=0;    
    for (int i=0; i<moves.length; i++)
    {
      Move m=moves[i];
      if (m.type.equals(ForEnd)) forCount--;
      
      System.out.print(i);
      if (i<=9) System.out.print("    ");
      else if (i<=99) System.out.print("   ");
      else if (i<=999) System.out.print("  ");
      else if (i<=9999) System.out.print(" ");
      for (int k=0; k<forCount; k++) System.out.print("  ");
      
      System.out.print(m.type);
      if (m.par1!=-1) System.out.print(" "+m.par1);
      if (m.par2!=-1) System.out.print(" "+m.par2);
      System.out.println();      
      if (m.type.equals(ForStart)) forCount++;      
    }
  }
  
  
  private void playMoves(Move[] moves, boolean[][] g, boolean doUpdate)
  {
    R=startR;
    C=startC;
    Dir=startDir;
    isPenUp=true;
    Score=0;
    Errors=0;
    
    //link locations of FOR and END
    //also initialize FOR counters
    List<Integer> forLoc=new ArrayList<Integer>();
    for (int i=0; i<moves.length; i++)
    {
      Move m=moves[i];

      if (m.type.equals(ForStart))
      {
        forLoc.add(i);
        m.counter=m.par1;
      }
      else if (m.type.equals(ForEnd))
      {
        int id=forLoc.remove(forLoc.size()-1);
        m.par1=id;          //link END to FOR id
        moves[id].par2=i;   //link FOR to END if
      }
    }
    
    int maxId=0;
    for (CommandId=0; CommandId<moves.length; )
    {    
      Move m=moves[CommandId];

      if (m.type.equals(Left))
      {
        Dir=(Dir-1+dr.length)%dr.length;
        if (CommandId==maxId) Score++;
        if (doUpdate) updateState();
      }
      else if (m.type.equals(Right))
      {
        Dir=(Dir+1)%dr.length;
        if (CommandId==maxId) Score++;
        if (doUpdate) updateState();
      }
      else if (m.type.equals(PenUp))
      {
        isPenUp=true;
        if (CommandId==maxId) Score++;
        if (doUpdate) updateState();
      }
      else if (m.type.equals(PenDown))
      {
        isPenUp=false;
        if (!g[R][C])
        {
          if (!grid[R][C])
          {
            Errors++;
            Score+=Penalty;
          }
          g[R][C]=true;
        }
        if (CommandId==maxId) Score++;
        if (doUpdate) updateState();
      }
      else if (m.type.equals(Forward))
      {
        if (CommandId==maxId) Score++;
        for (int i=0; i<m.par1; i++)
        {
          R=(R+dr[Dir]+N)%N;
          C=(C+dc[Dir]+N)%N;
          if (!isPenUp && !g[R][C])
          {
            if (!grid[R][C])
            {
              Errors++;
              Score+=Penalty;
            }
            g[R][C]=true;
          }
          if (doUpdate && parameters.isDefined("showAllSteps")) updateState();
        }
        if (doUpdate && !parameters.isDefined("showAllSteps")) updateState();
      }
      else if (m.type.equals(Back))
      {
        if (CommandId==maxId) Score++;
        for (int i=0; i<m.par1; i++)
        {
          R=(R-dr[Dir]+N)%N;
          C=(C-dc[Dir]+N)%N;
          if (!isPenUp && !g[R][C])
          {
            if (!grid[R][C])
            {
              Errors++;
              Score+=Penalty;
            }
            g[R][C]=true;
          }
          if (doUpdate && parameters.isDefined("showAllSteps")) updateState();
        }
        if (doUpdate && !parameters.isDefined("showAllSteps")) updateState();
      }      
      else if (m.type.equals(Jump))
      {
        R=(R+m.par1+N)%N;
        C=(C+m.par2+N)%N;
        if (CommandId==maxId) Score+=JC;
        if (!isPenUp && !g[R][C])
        {
          if (!grid[R][C])
          {
            Errors++;
            Score+=Penalty;
          }
          g[R][C]=true;
        }
        if (doUpdate) updateState();
      }        
      else if (m.type.equals(ForStart))
      {
        if (CommandId==maxId) Score+=FC;
        
        //for loop is completed, so go to END
        //make sure to reset the counter!
        if (m.counter==0)
        {
          CommandId=m.par2;         
          m.counter=m.par1;
        }
        else m.counter--;        
      }
      else if (m.type.equals(ForEnd))     //go to the start of the for loop
      {
        CommandId=m.par1-1;
      }
      CommandId++;
      maxId=Math.max(maxId,CommandId);
    }
  }
  
  private Move[] generateMoves()
  {
    int nesting=0;
    int numMoves=5*N;
    Move[] moves=new Move[numMoves];

    for (int i=0; i<numMoves; )
    {
      //force to use END to complete the FOR loops
      if (numMoves-i==nesting)
      {
        moves[i]=new Move(ForEnd,-1,-1);
        nesting--;
        i++;
        continue;
      }
      
      int id=randomInt(0,Moves.length-1);
      String m=Moves[id];
      
      Move move=null;
      if (m.equals(Left) || m.equals(Right) || m.equals(PenUp) || m.equals(PenDown))
      {
        move=new Move(m,-1,-1);
      }
      else if (m.equals(Forward) || m.equals(Back))
      {
        int dist=randomInt(1,N-1);
        move=new Move(m,dist,-1);
      }
      else if (m.equals(Jump))
      {
        int r=randomInt(0,N-1);
        int c=randomInt(0,N-1);
        move=new Move(m,r,c);
      }
      else if (m.equals(ForStart))
      {
        if (nesting==MaxNesting) continue;    //reached maximum nesting
        
        int iters=randomInt(MinIter,MaxIter);
        move=new Move(m,iters,-1);
        nesting++;
      }
      else if (m.equals(ForEnd))
      {
        if (nesting==0) continue;             //no for loop started
        
        move=new Move(m,-1,-1);
        nesting--;
      }
      
      moves[i]=move;
      i++;
    }
            
    return moves;
  }

  protected boolean isMaximize() {
      return false;
  }

  protected double run() throws Exception {
    init();
    return runAuto();
  }

  protected double runAuto() throws Exception {
    double Score = callSolution();
    if (Score < 0) {
      if (!isReadActive()) return getErrorScore();
      return fatalError();
    }
    return Score;
  }

  protected void timeout() {
    addInfo("Time", getRunTime());
    update();
  }


  private double callSolution() throws Exception {
    writeLine(N);
    writeLine(JC);
    writeLine(FC);
    // print grid
    for (int r = 0; r < N; r++)
      for (int c = 0; c < N; c++)
        writeLine(grid[r][c] ? "#" : ".");
    flush();
    if (!isReadActive()) return -1;

    R=startR;
    C=startC;
    Dir=startDir;
    isPenUp=true;    
    Errors=0;
    Score=0;
    updateState();

    try
    {
      // Get the solution
      startTime();

      Commands = Integer.parseInt(readLine());
      if (Commands<1 || Commands>JC*N*N)
        return fatalError("You must use between 1 and "+(JC*N*N)+" commands, inclusive.");                               

      int forCount=0;
      Fors=0;
      Jumps=0;
      Move[] moves = new Move[Commands];
      for (int i = 0; i < Commands; i++)
      {
        String line = readLine().trim();

        if (line.equals(Left) || line.equals(Right) || line.equals(PenUp) || line.equals(PenDown) || line.equals(ForEnd))
        {
          moves[i]=new Move(line,-1,-1);

          if (line.equals(ForEnd)) forCount--;

          if (forCount<0)
            return fatalError("You cannot have an END before a FOR");
        }
        else
        {
          String[] temp=line.split(" ");
          if (temp.length<=1 || temp.length>3)
            return fatalError("The following command does not have the correct number of parameters: "+line);

          if (temp[0].equals(Forward) || temp[0].equals(Back))
          {
            if (temp.length!=2)
              return fatalError("The command does not have the correct number of parameters: "+line);
            int dist=Integer.parseInt(temp[1]);
            if (dist<1 || dist>=N) 
              return fatalError("The "+temp[0]+" command must use between 1 and "+(N-1)+" steps inclusive: "+line);
            moves[i]=new Move(temp[0],dist,-1);
          }
          else if (temp[0].equals(Jump))
          {
            if (temp.length!=3)
              return fatalError("The command does not have the correct number of parameters: "+line);
            int rChange=Integer.parseInt(temp[1]);
            int cChange=Integer.parseInt(temp[2]);
            if (rChange<=-N || rChange>=N || cChange<=-N || cChange>=N)
              return fatalError("The jump command must use parameters in the range (-"+N+","+N+"): "+line);
            moves[i]=new Move(temp[0],rChange,cChange);
            Jumps++;
          }
          else if (temp[0].equals(ForStart))
          {
            if (temp.length!=2)
              return fatalError("The command does not have the correct number of parameters: "+line);
            int iters=Integer.parseInt(temp[1]);
            if (iters<MinIter || iters>MaxIter)
              return fatalError("The FOR loop must use between "+MinIter+" and "+MaxIter+" iterations, inclusive: "+line);
            moves[i]=new Move(temp[0],iters,-1);
            forCount++;
            Fors++;
            if (forCount>MaxNesting)
              return fatalError("You cannot use more than "+MaxNesting+" nested FOR loops");
          }
          else
            return fatalError("Illegal command: "+line);   
        }
      }
      if (forCount!=0)
        return fatalError("You didn't END all your FORs");      

      stopTime();

      if (debug)
      {
        System.out.println("\nYour moves:");
        printMoves(moves);      
      }

      playMoves(moves,painted,true);

      //add penalty for cells that should have been painted
      for (int r=0; r<N; r++)
        for (int c=0; c<N; c++)
          if (grid[r][c] && !painted[r][c])
          {
            Errors++;
            Score+=Penalty;
          }

      updateState();
    }
    catch (Exception e) {
      if (debug) System.out.println(e.toString());
      return fatalError("Cannot parse your output");
    }

    return Score;
  }



  protected void updateState()
  {
    if (hasVis())
    {      
      synchronized (updateLock) {      
        if (Commands>0)
        {
          addInfo("Commands",Commands);
          addInfo("FORs",Fors);
          addInfo("JUMPs",Jumps);
          addInfo("Command ID",CommandId);
        }
        addInfo("Errors", Errors);        
        addInfo("Score", Score);               
        addInfo("Time",  getRunTime());   
      }
      updateDelay();
    }
  }     

  private boolean inGrid(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N;
  }


  protected void paintContent(Graphics2D g)
  {  
    adjustFont(g, Font.SANS_SERIF, Font.PLAIN, String.valueOf("1"), new Rectangle2D.Double(0, 0, 0.5, 0.5));
    g.setStroke(new BasicStroke(0.005f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
    
    //draw grid
    g.setColor(Color.white);
    g.fillRect(0,0,N,N);    
    g.setColor(Color.black);
    for (int i = 0; i < N+1; i++)
    {
      g.drawLine(i,0,i,N);
      g.drawLine(0,i,N,i);
    }    
    
    //draw cells
    for (int r = 0; r < N; r++)
      for (int c = 0; c < N; c++)
      {          
        if (grid[r][c])
        {
          g.setColor(new Color(0,0,255,80));    //transparent blue
          g.fillRect(c, r, 1, 1);
        }
        if (painted[r][c])
        {
          g.setColor(new Color(255,0,0,80));    //transparent red
          g.fillRect(c, r, 1, 1);
        }        
      }

    //draw robot
    g.setStroke(new BasicStroke(0.05f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
    g.setColor(Color.black);
    GeneralPath gp = new GeneralPath();      
    int n=dr.length;
    gp.moveTo(C+0.5+0.3*dc[(Dir-2+n)%n]*dv[(Dir-2+n)%n], R+0.5+0.3*dr[(Dir-2+n)%n]*dv[(Dir-2+n)%n]);
    gp.lineTo(C+0.5+0.3*dc[Dir]*dv[Dir], R+0.5+0.3*dr[Dir]*dv[Dir]);
    gp.lineTo(C+0.5+0.3*dc[(Dir+2)%n]*dv[(Dir+2+n)%n], R+0.5+0.3*dr[(Dir+2)%n]*dv[(Dir+2+n)%n]);
    gp.lineTo(C+0.5+0.3*dc[(Dir-2+n)%n]*dv[(Dir-2+n)%n], R+0.5+0.3*dr[(Dir-2+n)%n]*dv[(Dir-2+n)%n]);

    if (isPenUp) g.draw(gp);
    else g.fill(gp);
  }

  private void init() {
    if (hasVis()) {
      setDefaultDelay(500);
      setContentRect(0, 0, N, N);
      setInfoMaxDimension(15, 13);
      addInfo("Seed", seed);
      addInfo("N", N);
      addInfo("JC", JC);
      addInfo("FC", FC);
      addInfoBreak();
      addInfo("Commands","NA");
      addInfo("JUMPs","NA");
      addInfo("FORs","NA");
      addInfo("Command ID","NA");
      addInfoBreak();
      addInfo("Errors",0);      
      addInfo("Score", "NA");
      addInfo("Time", 0);
      update();
    }
  }

  public class Move
  {
    String type;
    int par1;
    int par2;
    int counter;     //FOR counter

    public Move(String t, int p1, int p2)
    {
      type=t;
      par1=p1;
      par2=p2;
    }       
  }    

  public static void main(String[] args) {
      new MarathonController().run(args);
  }
}