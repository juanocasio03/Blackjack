#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>

using namespace std;
void print(int A[], int size) {
  for (int i = 0; i < size; i++) {
    cout << A[i] << endl;
  }
}

// funcion que despliega los valores de los elementos del array como cartas.
void printCard(int A[], int i) {
  // decision que determina el facevalue y lo despliega
  if (A[i] % 100 < 11)
    cout << setw(3) << A[i] % 100;
  else if (A[i] % 100 == 11)
    cout << setw(3) << "J";
  else if (A[i] % 100 == 12)
    cout << setw(3) << "Q";
  else if (A[i] % 100 == 13)
    cout << setw(3) << "K";
  else
    cout << setw(3) << "A";
  // decision que determina el suitvalue y lo despliega
  if (A[i] / 100 == 1)
    cout << "\u2663";
  else if (A[i] / 100 == 2)
    cout << "\u2666";
  else if (A[i] / 100 == 3)
    cout << "\u2665";
  else
    cout << "\u2660";

  cout << " |";
}

// Dado un array de tamaño 52 llenarlo de todos los enteros que
// representan las 52 cartas. No recibe el tamaño pues
// ya sabemos cuál es

void fillArray(int A[]) {
  int ind = 0;
  // i = suit value
  // j = suit value
  for (int i = 1; i < 5; i++) {
    for (int j = 2; j < 15; j++) {
      A[ind] = 100 * i + j;

      ind++;
    }
  }
}

// Dado un array de tamaño 52 barajar los elementos.

void shuffleArray(int A[], int size) {
  for (int i = 0; i < size; i++) {
    int j = rand() % size;
    swap(A[i], A[j]);
  }
}

void dealCards(int deck[], int player[], int dealer[], int size) {
  int topOfDeck, playerCards, dealerCards;
  playerCards = 0;
  dealerCards = 0;

  for (int i = 0; i < size; i++) {
    if (i == 0) {
      player[playerCards] = deck[i];
      playerCards++;
    } else if (i % 2 == 0) {
      player[playerCards] = deck[i];
      playerCards++;
    } else {
      dealer[dealerCards] = deck[i];
      dealerCards++;
    }
  }
}

void printGame(int deck[], int player[], int dealer[], int size) {
  int topOfDeck = 0;
}

// Algunas cosas que debes hacer en main:
//  * pedir input del usuario relacionado al modo de "shuffing"
//  * inicializar a srand() de acuerdo
//  * crear arreglo de tamaño 52 y pasarlo a fill array
//  * pasarlo a shuffleArray, si corresponde
//  * imprimir el arreglo

int main() {
  char shuffle;
  unsigned int seed;
  int deck[52];
  int size = 52;
  int player[52];
  int dealer[52];
  cout << "Shuffle: [n | s | u <seed>]: ";
  cin >> shuffle;

  fillArray(deck);

  if (shuffle == 'n') {
    dealCards(deck, player, dealer, size);
  }

  else if (shuffle == 's') {
    srand(time(0));
    shuffleArray(deck, size);
    dealCards(deck, player, dealer, size);
  }

  else if (shuffle == 'u') {
    cin >> seed;
    srand(seed);
    shuffleArray(deck, size);
    dealCards(deck, player, dealer, size);

    int dealerCards = 0;
    int playerCards = 0;
    int n = 0;
    for (int round = 1; round < 4; round++) {
      cout << "Round " << round << ": " << endl;
      cout << "Player Dealer" << endl;
      // print first two cards for player and dealer
      for (int i = 0; i < n + 2; i++) {
        cout << "|";
        printCard(player, n + i);
        for (int j = 0; j < n + 1; j++) {
          printCard(dealer, n + i);
          cout << endl;
        }
      }
      if (round != 1) {
        for (int i = 2; i < round + 1; i++) {
          cout << "|";
          printCard(player, n + i);
          for (int j = 0; j < n + 1; j++) {
            printCard(dealer, n + i);
            cout << endl;
          }
        }
      }

      cout << endl;
    }
  }
}
