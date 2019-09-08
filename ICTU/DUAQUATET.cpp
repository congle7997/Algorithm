#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

char antiStorm(char direction, char state) {
  char newState;
  if (state == 'E') {
    if (direction == 'L') {
      newState = 'N';
    } else if (direction == 'R') {
      newState = 'S';
    } else if (direction == 'B') {
      newState = 'W';
    } else if (direction == 'C') {
      newState = 'E';
    }
  } else if (state == 'W') {
    if (direction == 'L') {
      newState = 'S';
    } else if (direction == 'R') {
      newState = 'N';
    } else if (direction == 'B') {
      newState = 'E';
    } else if (direction == 'C') {
      newState = 'W';
    }
  } else if (state == 'S') {
    if (direction == 'L') {
      newState = 'E';
    } else if (direction == 'R') {
      newState = 'W';
    } else if (direction == 'B') {
      newState = 'N';
    } else if (direction == 'C') {
      newState = 'S';
    }
  } else if (state == 'N') {
    if (direction == 'L') {
      newState = 'W';
    } else if (direction == 'R') {
      newState = 'E';
    } else if (direction == 'B') {
      newState = 'S';
    } else if (direction == 'C') {
      newState = 'W';
    }
  }

  return newState;
}

int main() {
  string z;
  cin >> z;

  struct Point {
    int x;
    int y;
  };

  Point p;
  p.x = 0;
  p.y = 0;

  char state;

  for (int i = 0; i < z.size(); i++) {
    char data = z[i];

    if (data == 'L' || data == 'R' || data == 'B' || data == 'C') {
      data = antiStorm(data, state);
    }

    if (data == 'E') {
      p.x += 1;
      state = 'E';
      //cout << p.x << " " << p.y << endl;
    } else if (data == 'W') {
      p.x -= 1;
      state = 'W';
      //cout << p.x << " " << p.y << endl;
    } else if (data == 'S') {
      p.y -= 1;
      state = 'S';
      //cout << p.x << " " << p.y << endl;
    } else if (data == 'N') {
      p.y += 1;
      state = 'N';
      //cout << p.x << " " << p.y << endl;
    }
  }

  float result = sqrt(pow((0 - p.x), 2) + pow((0 - p.y), 2));
  printf("%0.3f", result);
}
