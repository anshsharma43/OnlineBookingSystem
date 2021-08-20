#include<stdio.h>

#include<iostream>

#include<stdlib.h>

#include<malloc.h>

#include<string.h>

using namespace std;
struct train {
  int bs;
  int ds;
  int ns;
  int fare;
  int trno;
  struct train * next;
}* start = NULL, * q, * t;
struct user {
  char name[100];
  char pass[20];
  int age;
  int utno;
  int uns;
  int ufare;
  struct user * next1;
}* start1, * q1, * t1;
class tra {
  public:
    void insertrain() {
      int bss, dss, nss, fares, trnos;
      cout << "\nEnter the Train Number: ";
      cin >> trnos;
      cout << "\nEnter the Boarding Station City Code: ";
      cin >> bss;
      cout << "\nEnter the destination Station City Code: ";
      cin >> dss;
      cout << "\nEnter the no. of seats in the train: ";
      cin >> nss;
      cout << "\nEnter the fare of the each seat: ";
      cin >> fares;
      int num;
      t = (struct train * ) malloc(sizeof(struct train));
      t -> bs = bss;
      t -> ds = dss;
      t -> ns = nss;
      t -> fare = fares;
      t -> trno = trnos;
      if (start == NULL) {
        t -> next = NULL;
        start = t;
      } else {
        t -> next = start;
        start = t;
      }
    }
  void deletetrain() {
    int bss, dss;
    cout << "Enter the boarding station city code: ";
    cin >> bss;
    cout << "Enter the destination station city code: ";
    cin >> dss;
    struct train * temp = start, * prev;
    if (temp != NULL && temp -> bs == bss && temp -> ds == dss) {
      start = temp -> next;
      free(temp);
      return;
    }
    while (temp != NULL && temp -> bs != bss && temp -> ds != dss) {
      prev = temp;
      temp = temp -> next;
    }
    if (temp == NULL) return;
    prev -> next = temp -> next;
    free(temp);
  }
  void displaytrain() {
    if (start == NULL) {
      printf("List is empty!!");
    } else {
      q = start;
      cout << "The train list is:\n";
      cout << "Train Number" << "\t" << "BOARDING STATION" << "\t" << "DESTINATION STATION" << "\t" << "NO. OF SEATS" << "\t\t" << "FARE";
      while (q != NULL) {
        cout << "\n" << q -> trno << "\t\t\t" << q -> bs << "\t\t\t" << q -> ds << "\t\t\t" << q -> ns << "\t\t" << "Rs." << q -> fare << "\n";
        q = q -> next;
      }
    }
  }
  void updatetrain() {
    int trnos, nss, fares;
    displaytrain();
    cout << "\nEnter the train number to be updated : ";
    cin >> trnos;
    struct train * w, * tmp;
    w = start;
    while (w != NULL) {
      if (w -> trno == trnos) {
        cout << "\nTrain is found";
        cout << "\nEnter the updated number of seats: ";
        cin >> nss;
        cout << "\nEnter the updated Fare: ";
        cin >> fares;
        w -> ns = nss;
        w -> fare = fares;
        break;
      } else {
        w = w -> next;
      }
    }
    if (w == NULL) {
      printf("Train not found");
    }
  }
};
class passenger {
  public:
    tra tt;
  void signup() {
    char names[100], passs[20];
    int ages;
    cout << "\nEnter the User Name: ";
    cin >> names;
    cout << "\nEnter the Age: ";
    cin >> ages;
    cout << "\nEnter the password ";
    cin >> passs;
    int num;
    t1 = (struct user * ) malloc(sizeof(struct user));
    strcpy(t1 -> name, names);
    t1 -> age = ages;
    strcpy(t1 -> pass, passs);
    if (start == NULL) {
      t1 -> next1 = NULL;
      start1 = t1;
    } else {
      t1 -> next1 = start1;
      start1 = t1;
    }
  }
  void login() {
    char names[100], passs[20];
    cout << "USERNAME: ";
    cin >> names;
    cout << "PASSWORD: ";
    cin >> passs;
    struct user * temp1 = start1, * prev1;
    int ch11;
    if (temp1 != NULL && (strcmp(temp1 -> name, names) == 0) && (strcmp(temp1 ->
        pass, passs) == 0)) {
      do {
        cout << "\n1.Reservation\n2.Cancellation\n3.Return to main menu";
        cout << "\nEnter your Choice: ";
        cin >> ch11;
        switch (ch11) {
        case 1: {
          reservation();
          break;
        }
        case 2: {
          cancel();
          break;
        }
        }
      }
      while (ch11 <= 2);
    }
    while (temp1 != NULL && (strcmp(temp1 -> name, names) != 0) &&
      (strcmp(temp1 -> pass, passs) != 0)) {
      prev1 = temp1;
      temp1 = temp1 -> next1;
    }
    if (temp1 == NULL) return;
  }
  void reservation() {
    tt.displaytrain();
    int trno11, nss1, tf;
    cout << "Enter Your Train Number for Booking";
    cin >> trno11;
    struct train * w1, * tmp1;
    w1 = start;
    while (w1 != NULL) {
      if (w1 -> trno == trno11) {
        cout << "\nTrain is found";
        cout << "\nEnter the number of seats: ";
        cin >> nss1;
        if (nss1 <= w1 -> ns) {
          w1 -> ns = w1 -> ns - nss1;
          cout << "Total Fare: " << nss1 * w1 -> fare;
          tf = nss1 * w1 -> fare;
          payment(tf);
        } else {
          cout << "\nSeats Not Available";
          cout << "No. Of seats available: ";
          cout << w1 -> ns;
        }
        break;
      } else {
        w1 = w1 -> next;
      }
    }
    if (w1 == NULL) {
      printf("Train not found");
    }
    return;
  }
  void cancel() {
    char username1[100], passs11[20];
    cout << "\nUsername: ";
    cin >> username1;
    cout << "\nPassword: ";
    cin >> passs11;
    struct user * temp12 = start1, * prev1;
    int ch112;
    if (temp12 != NULL && (strcmp(temp12 -> name, username1) == 0) &&
      (strcmp(temp12 -> pass, passs11) == 0)) {
      cout << "Enter the number of tickets to be cancelled: ";
      cin >> ch112;
      temp12 -> uns = temp12 -> uns - ch112;
      cout << "\nCancellation Done.";
    }
    while (temp12 != NULL && (strcmp(temp12 -> name, username1) != 0) &&
      (strcmp(temp12 -> pass, passs11) != 0)) {
      prev1 = temp12;
      temp12 = temp12 -> next1;
    }
    if (temp12 == NULL) return;
    return;
  }
  void payment(int s) {
    cout << "\nFare Details" << endl;
    cout << "\nThe total fare:" << s;
    cout << "\nChoose the payment options:" << endl;
    cout << "\n1.Credit card" << endl << "\n2.Phonepe" << endl << "\n3.NetBanking\n" << endl;
    int ch;
    scanf("%d", & ch);
    switch (ch) {
    case 1:
      creditcard();
      break;
    case 2:
      Phonepe();
      break;
    case 3:
      NetBanking();
      break;
    }
  }
  char cdno[20];
  int cvv;
  char expiry[8];
  void creditcard() {
    cout << "Welcome to Billdesk Payment Gateway" << endl;
    cout << "Enter the card number:" << endl;
    cin >> cdno;
    cout << "Enter the expiry date of the card" << endl;
    cin >> expiry;
    cout << "Enter your CVV Number:" << endl;
    cin >> cvv;
    cout << "The payment is successful";
  }
  char upi[5] = "6837";
  char upi1[5];
  void Phonepe() {
    cout << "Enter the Upi pin" << endl;
    cin >> upi1;
    if (strcmp(upi1, upi) == 0) {
      cout << "Payment successful" << endl;
    } else {
      cout << "Payment unsuccessful" << endl;
      Phonepe();
    }
  }
  char userid[10],password[10];
  char mall[40] = "Vellore";
  char mall1[40];
  void NetBanking() {
    cout << "Netbanking Login:" << endl;
    cout << "Enter the User-id:" << endl;
    cin >> userid;
    cout << "Enter the password" << endl;
    cin >> password;
    cout << "What is the mall closest from your house:" << endl;
    cin >> mall1;
    if (strcmp(mall1, mall) == 0) {
      cout << "Payment successful" << endl;
    } else {
      cout << "Payment unsuccessful" << endl;
      NetBanking();
    }
  }
};
void user1() {
  int ch;
  passenger p;
  do {
    cout << "...........USER MENU...........\n";
    cout << "\n1.SignUp\n2.Login\n";
    cout << "3.Return to main menu\n";
    cout << "Enter your choice:";
    cin >> ch;
    char c;
    cout << endl;
    switch (ch) {
    case 1:
      do {
        p.signup();
        cout << "Do you want to add one more record?\n";
        cout << "y-for Yes\nn-for No\n";
        cin >> c;
      }
      while (c == 'y');
      break;
    case 2:
      do {
        p.login();
        cout << "Do you want to login with another account: ";
        cin >> c;
      }
      while (c == 'y');
      break;
    }
  }
  while (ch <= 2);
}
void admin() {
  tra t;
  char password[10];
  char pass[] = "admin";
  cout << "Enter the admin password: ";
  cin >> password;
  int ch;
  char c;
  if (strcmp(pass, password) != 0) {
    cout << "Enter the password correctly \n";
    cout << "You are not permitted to logon this mode\n";
  }
  if (strcmp(pass, password) == 0) {
    char c;
    do {
      cout << "...........ADMINISTRATOR MENU...........\n";
      cout << "1.Add details\n2.Delete details\n3.Update\n";
      cout << "4.Display details\n";
      cout << "5.Return to main menu\n";
      cout << "Enter your choice:";
      cin >> ch;
      cout << endl;
      switch (ch) {
      case 1:
        do {
          cout << "Cities" << "\t\t" << "Codes";
          cout << "\nKolkata" << "\t\t" << 1;
          cout << "\nDurgapur" << "\t" << 2;
          cout << "\nRaniganj" << "\t" << 3;
          cout << "\nAsansol" << "\t\t" << 4;
          cout << "\nSiliguri" << "\t" << 5;
          t.insertrain();
          cout << "Do you want to add one more record?\n";
          cout << "y-for Yes\nn-for No\n";
          cin >> c;
        }
        while (c == 'y');
        break;
      case 2:
        do {
          t.deletetrain();
          cout << "Do you want to delete one more record?\n";
          cout << "y-for Yes\nn-for No\n";
          cin >> c;
        }
        while (c == 'y');
        break;
      case 3:
        do {
          t.updatetrain();
          cout << "Do you want to update more record?\n";
          cout << "y-for Yes\nn-for No\n";
          cin >> c;
        }
        while (c == 'y');
        break;
      case 4:
        t.displaytrain();
        break;
      }
    }
    while (ch <= 4);
  }
}
int main() {
  int ch;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  cout << ".........WELCOME TO RAILWAY RESERVATION SYSTEM........\n";
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  do {
    cout << "^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
    cout << "1.Admin mode\n2.User mode\n3.Exit\n";
    cout << "Enter your choice:";
    cin >> ch;
    cout << endl;
    switch (ch) {
    case 1:
      admin();
      break;
    case 2:
      user1();
      break;
    case 3:
      exit(0);
    }
  }
  while (ch <= 3);
  return 0;
}
