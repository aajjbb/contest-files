// C++17
#include <iostream>
using namespace std;

int main()
{
  int T,S,C,N;
  double P;
  cin >> T >> S >> C >> N >> P;

  int targets[T][N];
  int targetCounts[N];

  for (int i=0; i<T; i++)
  {
    for (int k=0; k<N; k++)
    {
      targets[i][k]=0;
      targetCounts[k]=0;
    }
  }

  int sources[S][N];
  for (int i=0; i<S; i++)
  {
    char c;
    for (int k=0; k<N; k++)
    {
      cin >> c;
      sources[i][k]=c-'0';
    }
  }


  int numMoves=30;
  int moves=0;
  for (int i=0; moves<numMoves; i++)
  {
    int idS=i%S;
    int idT=-1;

    for (int t=0; t<T; t++)
    {
      bool canPlace=true;
      for (int k=0; k<N; k++)
        if (sources[idS][k]!=0 && targets[t][k]!=0)
          canPlace=false;

      if (canPlace)
      {
        idT=t;
        break;
      }
    }

    if (idT>=0)
    {
      //place plate
      for (int k=0; k<N; k++)
        if (sources[idS][k]!=0)
        {
          targets[idT][k]=sources[idS][k];
          targetCounts[idT]++;
        }

      //clear target plate
      if (targetCounts[idT]==N)
      {
        targetCounts[idT]=0;
        for (int k=0; k<N; k++) targets[idT][k]=0;
      }

      cout << idS << " " << idT << endl;
      cout.flush();
    }
    else
    {
      //discard plate
      cout << idS << " D" << endl;
      cout.flush();
    }

    moves++;

    //read new plate and elapsed time
    for (int k=0; k<N; k++)
    {
      char c;
      cin >> c;
      sources[idS][k]=c-'0';
    }

    int elapsedTime;
    cin >> elapsedTime;
  }

  cout << "-1" << endl;
  cout.flush();
  return 0;
}
