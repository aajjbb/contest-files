import java.awt.*;
import java.awt.geom.*;
import java.util.*;
import java.io.*;
import javax.imageio.*;
import java.util.List;
import java.util.ArrayList;
import java.awt.image.BufferedImage;

import com.topcoder.marathon.*;

public class PieMakerTester extends MarathonAnimatedVis {
  //parameter ranges
  private static final int minT = 1, maxT = 6;      // number of target plates range
  private static final int minS = 1, maxS = 6;      // number of source plates range
  private static final int minC = 1, maxC = 6;      // number of colours range
  private static final int minN = 4, maxN = 10;     // number of pie sections range  
  private static final double minP = 0.05, maxP = 0.3;     // plate fill ratio range

  //Inputs
  private int T;            // number of target plates
  private int S;            // number of source plates
  private int C;            // number of colours
  private int N;            // number of pie sections
  private double P;         // plate fill ratio
  
  //Constants
  private static final int Empty=0;
  private static final int MaxMoves=1000;
  
  //Graphics   
  Color[] colors={Color.cyan, Color.red, Color.green, Color.magenta, Color.orange, Color.blue};

  //State Control
  private int[][] targets;               // targets state
  private int[][] sources;               // sources state
  private int numMoves;                  // number of moves used
  private int clearedMixed;              // number of cleared with mixed colours
  private int clearedSingle;             // number of cleared with single colour
  private int selectedSource=-1;         // selected source plate
  private int selectedTarget=-1;         // selected target plate
  private char userAction;
  private int M;                         // grid width
  private double score;


  protected void generate()
  {
    T = randomInt(minT, maxT);
    S = randomInt(minS, maxS);   
    C = randomInt(minC, maxC);
    N = randomInt(minN, maxN);    
    P = randomDouble(minP, maxP);    

    //Special cases
    if (seed == 1)
    {
      T = 2;
      S = 2;
      C = 2;
      N = minN;
    }
    else if (seed == 2)
    {
      T = maxT;
      S = maxS;
      C = maxC;
      N = maxN;
    }

    //User defined parameters
    if (parameters.isDefined("T")) T = randomInt(parameters.getIntRange("T"), minT, maxT);
    if (parameters.isDefined("S")) S = randomInt(parameters.getIntRange("S"), minS, maxS);
    if (parameters.isDefined("C")) C = randomInt(parameters.getIntRange("C"), minC, maxC);
    if (parameters.isDefined("N")) N = randomInt(parameters.getIntRange("N"), minN, maxN);    
    if (parameters.isDefined("P")) P = randomDouble(parameters.getDoubleRange("P"), minP, maxP);    

    M=Math.max(T,S);

    targets = new int[T][N];
    sources = new int[S][N];
    numMoves = 0;    
    clearedMixed = 0;
    clearedSingle = 0;

    //generate source plates
    for (int i=0; i<S; i++) generatePlate(i);

    if (debug)
    {
      System.out.println("Number of target plates, T = " + T);
      System.out.println("Number of source plates, S = " + S);
      System.out.println("Number of colours, C = " + C);
      System.out.println("Number of pie sections, N = " + N);
      System.out.println("Plate fill ratio, P = "+ P);
      System.out.println("Source plates:");
      for (int i=0; i<S; i++)
      {
        System.out.print("plate "+i+": ");
        for (int k=0; k<N; k++) System.out.print(sources[i][k]);
        System.out.println();
      }
    }
  }


  protected String generatePlate(int id)
  {
    int colour=randomInt(1,C);
    String plate;

    while(true)
    {
      int numFilled=0;
      plate="";
      for (int i=0; i<N; i++)
      {
        if (randomDouble(0,1)<P)
        {
          sources[id][i]=colour;
          plate+=colour;
          numFilled++;
        }
        else
        {
          sources[id][i]=Empty;
          plate+=Empty;
        }
      }
      //must have at least one piece, but cannot have all the pieces
      if (numFilled>=1 && numFilled<=N-1) break;
    }

    return plate;
  }


  protected boolean isMaximize() {
      return true;
  }

  protected double run() throws Exception
  {
    init();

    return runAuto();
  }


  protected double runAuto() throws Exception
  {
    double score = callSolution();
    if (score < 0) {
      if (!isReadActive()) return getErrorScore();
      return fatalError();
    }
    return score;
  }

  protected void timeout() {
    addInfo("Time", getRunTime());
    update();
  }


  private double callSolution() throws Exception
  {
    writeLine(""+T);
    writeLine(""+S);
    writeLine(""+C);
    writeLine(""+N);
    writeLine(""+P);
    for (int i=0; i<S; i++)
    {
      String s="";
      for (int k=0; k<N; k++) s+=sources[i][k];
      writeLine(s);
    }

    flush();
    if (!isReadActive()) return -1;


    updateState();

    try
    {     
      for (numMoves=1; numMoves<=MaxMoves; numMoves++)
      {
        if (debug) System.out.println("\nmove "+numMoves);

        selectedSource=-1;
        selectedTarget=-1;      

        //read solution output
        startTime();        
        String move=readLine();
        stopTime();

        if (move.equals("-1")) break;

        String[] temp=move.split(" ");
        if (temp.length!=2)
          return fatalError("Each move must contain exactly 2 elements separated by space, formatted as (id action): " + move);

        int id=Integer.parseInt(temp[0]);
        if (id<0 || id>=S)
          return fatalError("Source id must be between 0 and "+(S-1)+", inclusive. id "+id+" was given.");

        selectedSource=id;        
        userAction='S';   //select
        if (!parameters.isDefined("noanimate")) updateState();

        String action=temp[1];

        if (action.equals("D"))
        {
          userAction='D';   //discard
          String plate=generatePlate(id);
          writeLine(plate);
          if (debug)
          {
            System.out.println("discarding source "+id);
            System.out.println("received "+plate);
          }
        }
        else if (action.equals("L"))
        {
          rotateLeft(id);
          userAction='R';   //rotate
          if (debug) System.out.println("rotating left source "+id);                  
        }
        else if (action.equals("R"))
        {
          rotateRight(id);
          userAction='R';   //rotate
          if (debug) System.out.println("rotating right source "+id);                                        
        }        
        else
        {
          try
          {
            int id2=Integer.parseInt(action);           
            if (id2<0 || id2>=T)
              return fatalError("Target id must be between 0 and "+(T-1)+", inclusive. id "+id2+" was given.");  

            //check that we can place plate
            for (int i=0; i<N; i++)
              if (sources[id][i]!=Empty && targets[id2][i]!=Empty)
                return fatalError("Cannot place source plate "+id+" on target plate "+id2);

            if (debug) System.out.println("Placing source "+id+" onto target "+id2);                

            selectedSource=-1;
            selectedTarget=id2;
            String newPlate=placePlate(id,id2);
            if (debug) System.out.println("received "+newPlate);            
            writeLine(newPlate);     
          }
          catch (Exception e) {
            return fatalError("Unrecognized action: "+action);
          }          
        }

        writeLine(""+getRunTime());      
        flush();           

        if (!parameters.isDefined("noanimate")) updateState();
      }
      if (parameters.isDefined("noanimate")) updateState();
    }
    catch (Exception e) {
      if (debug) System.out.println(e.toString());
      return fatalError("Cannot parse your output");
    }

    return score;
  }

  protected void rotateLeft(int id)
  {
    int temp=sources[id][N-1];
    for (int i=N-1; i>=1; i--) sources[id][i]=sources[id][i-1];
    sources[id][0]=temp;
  }    

  protected void rotateRight(int id)
  {
    int temp=sources[id][0];
    for (int i=0; i<N-1; i++) sources[id][i]=sources[id][i+1];
    sources[id][N-1]=temp;
  }  

  protected String placePlate(int source, int target)
  {          
    int count=0;
    for (int i=0; i<N; i++)        
      if (sources[source][i]!=Empty)
      {
        targets[target][i]=sources[source][i];
        count++;
      }

    score+=count;
    if (debug) System.out.println("plate scores "+count);

    //is target plate full?
    boolean full=true;
    boolean oneColour=true;
    for (int i=0; i<N; i++)
    {
      if (targets[target][i]==Empty) full=false;
      if (targets[target][i]!=targets[target][0]) oneColour=false;
    }

    //get new plate
    String plate=generatePlate(source);             

    if (full)
    {
      userAction='C';     //clear!
      if (!parameters.isDefined("noanimate")) updateState();     
      selectedTarget=-1;

      if (oneColour)
      {
        score+=N*N;
        clearedSingle++;
        if (debug) System.out.println("cleared target "+target+" with one colour, scores "+(N*N));
      }
      else
      {
        score+=N;
        clearedMixed++;
        if (debug) System.out.println("cleared target "+target+" with mixed colours, scores "+N);
      }

      //clear target plate
      for (int i=0; i<N; i++) targets[target][i]=Empty;
    }

    return plate;
  }


  protected void updateState()
  {
    if (hasVis())
    {
      synchronized (updateLock) {
        addInfo("Moves", numMoves);
        addInfo("Cleared Mixed", clearedMixed);
        addInfo("Cleared Single", clearedSingle);        
        addInfo("Time",  getRunTime());
        addInfo("Score", shorten(score));
      }
      updateDelay();
    }
  }


  protected void paintContent(Graphics2D g)
  {
    g.setColor(Color.white);
    g.fillRect(0,0,M,2);

    //separating line
    g.setColor(Color.black);
    g.setStroke(new BasicStroke(0.005f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
    g.drawLine(0,1,M,1);

    //text
    g.setColor(Color.black);
    adjustFont(g, Font.SANS_SERIF, Font.PLAIN, "Target", new Rectangle2D.Double(0, 0, 0.25, 0.25));
    drawString(g, "Target", new Rectangle2D.Double(M/2.0, 0.05, 0, 0));    
    drawString(g, "Source", new Rectangle2D.Double(M/2.0, 1.95, 0, 0));      


    double angleChange=Math.PI*2.0/N;

    //draw target plates
    for (int i=0; i<T; i++)
    {
      for (int k=0; k<N; k++)
      {
        GeneralPath gp = new GeneralPath();
        gp.moveTo(i+0.5, 0.5);    //center of plate
        double angle=k*angleChange;
        gp.lineTo(i+0.5+0.4*Math.cos(angle), 0.5-0.4*Math.sin(angle));
        angle+=angleChange;
        gp.lineTo(i+0.5+0.4*Math.cos(angle), 0.5-0.4*Math.sin(angle));

        if (targets[i][k]!=Empty)
        {
          g.setColor(colors[targets[i][k]-1]);            
          g.fill(gp);            
        }
        g.setColor(Color.gray);
        g.draw(gp);                   
      }
    }

    //draw source plates
    for (int i=0; i<S; i++)
    {
      for (int k=0; k<N; k++)
      {
        GeneralPath gp = new GeneralPath();
        gp.moveTo(i+0.5, 1.5);    //center of plate
        double angle=k*angleChange;
        gp.lineTo(i+0.5+0.4*Math.cos(angle), 1.5-0.4*Math.sin(angle));
        angle+=angleChange;
        gp.lineTo(i+0.5+0.4*Math.cos(angle), 1.5-0.4*Math.sin(angle));

        if (sources[i][k]!=Empty)
        {
          g.setColor(colors[sources[i][k]-1]);
          g.fill(gp);
        }
        g.setColor(Color.gray);
        g.draw(gp);    
      }      
    }    
    
    // draw selected and rotated plates
    if (selectedTarget!=-1)
    {
      if (userAction=='C') g.setColor(Color.green);   //cleared
      else g.setColor(Color.blue);    //selected      

      g.setStroke(new BasicStroke(0.025f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
      g.drawRect(selectedTarget,0,1,1);
    }
    if (selectedSource!=-1)
    {
      if (userAction=='S') g.setColor(Color.blue);    //selected
      if (userAction=='R') g.setColor(Color.cyan);    //rotated
      if (userAction=='D') g.setColor(Color.red);    //discarded

      g.setStroke(new BasicStroke(0.025f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
      g.drawRect(selectedSource,1,1,1);
    }
  }


  private double shorten(double a)
  {
    return (double)Math.round(a * 1000.0) / 1000.0;
  }


  private void init()
  {
    score=0;

    if (hasVis())
    {
      setDefaultDelay(1000);    //this needs to be first

      setContentRect(0, 0, M, 2);
      setInfoMaxDimension(20, 11);

      addInfo("Seed", seed);
      addInfo("T", T);
      addInfo("S", S);
      addInfo("C", C);
      addInfo("N", N);      
      addInfo("P", shorten(P));

      addInfoBreak();
      addInfo("Moves", 0);
      addInfo("Cleared Mixed", 0);
      addInfo("Cleared Single", 0);

      addInfoBreak();
      addInfo("Time", 0);
      addInfo("Score", score);        
      update();
    }
  }
        

  public static void main(String[] args) {
      new MarathonController().run(args);
  }
}