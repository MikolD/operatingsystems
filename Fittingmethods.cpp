#include <iostream>
using namespace std;


class Fittingmethods{

public:
        int choice;
    void fittingmethods(){
        cout << "--------------------------------------------------------"<<endl;
        cout << "You selected Memory Management Scheme | Fitting methods"<<endl;
        cout << "--------------------------------------------------------"<<endl;
        cout << "1. To use Worst-fit Enter 1 "<<endl;
        cout << "2. To use Best-fit Enter 2 "<<endl;
        cout << "3. To use First-fit Enter 3 "<<endl;
        cout << "\nChoice : ";
        cin >> choice;

    if (choice == 1){
        worstfit();
    }
    else if (choice == 2){
        bestfit();
    }
    else if (choice == 3){
        firstfit();
    }
}




    void firstfit() {
  int frag[25], b[25], f[25], i, j, nb, nf, temp, highest = 0;
  static int bf[25], ff[25];

  cout << ".........................................."<<endl;
  cout << "Memory Management Scheme - First Fit"<<endl;
  cout << ".........................................."<<endl;
  cout << "\nEnter the number of blocks:";
  cin >> nb;
  cout << "Enter the number of files:";
  cin >> nf;
  cout << "\nEnter the size of the blocks:-\n";
  for (i = 1; i <= nb; i++) {
    cout << "Block " << i << ":";
    cin >> b[i];
  }
  cout << "Enter the size of the files :-\n";
  for (i = 1; i <= nf; i++) {
    cout << "File " << i << ":";
    cin >> f[i];
  }
  for (i = 1; i <= nf; i++) {
    for (j = 1; j <= nb; j++) {
      if (bf[j] != 1) //if bf[j] is not allocated
      {
        temp = b[j] - f[i];
        if (temp >= 0)
          if (highest < temp) {
            ff[i] = j;
            highest = temp;
          }
      }
    }
    frag[i] = highest;
    bf[ff[i]] = 1;
    highest = 0;
  }
  printf("\nFile no:\tFile size :\tBlock no:\tBlock size:\tFragment");
  for (i = 1; i <= nf; i++) {
    cout << "\n" << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i];
  }
}

void bestfit() {
  int frag[10], b[10], f[10], i, j, nb, nf, temp, lowest = 10000;
  static int bf[10], ff[10];

  cout << ".........................................."<<endl;
  cout << "Memory Management Scheme - Best Fit";
  cout << ".........................................."<<endl;
  cout << "Enter the number of blocks:";
  cin >> nb;
  cout << "Enter the number of files:";
  cin >> nf;
  cout << "\nEnter the size of the blocks:-\n";
  for (i = 1; i <= nb; i++) {
    cout << "Block " << i << ":";
    cin >> b[i];
    cout << "Enter the size of the files :-\n";
    for (i = 1; i <= nf; i++) {
      cout << "File " << i << ":";
      cin >> f[i];
    }
    for (i = 1; i <= nf; i++) {
      for (j = 1; j <= nb; j++) {
        if (bf[j] != 1) {
          temp = b[j] - f[i];
          if (temp >= 0) {
            if (lowest > temp) {
              ff[i] = j;
              lowest = temp;
            }
          }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
      }
      cout << "\nFile No\tFile Size \tBlock No\tBlock Size\tFragment";
      for (i = 1; i <= nf && ff[i] != 0; i++)
        cout << "\n" << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;
    }
  }
}
void worstfit() {

  int frag[25], b[25], f[25], i, j, nb, nf, temp;
  static int bf[25], ff[25];

  cout << ".........................................."<<endl;
  cout << "Memory Management Scheme - Worst Fit"<<endl;
  cout << ".........................................."<<endl;
  cout << "Enter the number of blocks: ";
  cin >> nb;
  cout << "Enter the number of files: ";
  cin >> nf;
  cout << "\nEnter the size of the blocks:-\n";
  for (i = 1; i <= nb; i++) {
    cout << "Block " << i << ": ";
    cin >> b[i];
  }
  cout << "Enter the size of the files :-\n";
  for (i = 1; i <= nf; i++) {
    cout << "File " << i << ": ";
    cin >> f[i];
  }
  for (i = 1; i <= nf; i++) {
    for (j = 1; j <= nb; j++) {
      if (bf[j] != 1) {
        temp = b[j] - f[i];
        if (temp >= 0) {
          ff[i] = j;
          break;
        }
      }
    }
    frag[i] = temp;
    bf[ff[i]] = 1;
  }
  cout << ("\nFile no:\tFile size :\tBlock no:\tBlock size:\tFragment");
  for (i = 1; i <= nf; i++)
    cout << "\n" << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;

}

};
