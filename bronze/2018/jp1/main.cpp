#include <bits/stdc++.h>

using namespace std;

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);

  int mower_blx = nxt();
  int mower_bly = nxt();

  int mower_trx = nxt();
  int mower_try = nxt();


  int cowfeed_blx = nxt();
  int cowfeed_bly = nxt();

  int cowfeed_trx = nxt();
  int cowfeed_try = nxt();

  int mower_width = (mower_trx - mower_blx);
  int mower_height = (mower_try - mower_bly);
  int mower_area = mower_width * mower_height;

  // Check if bottom left is covered. If it is, find the 
  bool blx_covered = cowfeed_blx <= mower_blx && mower_blx <= cowfeed_trx;
  bool trx_covered = cowfeed_blx <= mower_trx && mower_trx <= cowfeed_trx;

  bool bly_covered = cowfeed_bly <= mower_bly && mower_bly <= cowfeed_try;
  bool try_covered = cowfeed_bly <= mower_try && mower_try <= cowfeed_try;

  bool bl_covered = blx_covered && bly_covered;
  bool tl_covered = blx_covered && try_covered;
  bool tr_covered = trx_covered && try_covered;
  bool br_covered = trx_covered && bly_covered;

  // Entire billboard is covered
  if (bl_covered && tl_covered && tr_covered && br_covered) {
    cout << 0 << endl;
  }

  //Three or four corners are exposed
  if (bl_covered + tl_covered + tr_covered + br_covered <= 1) {
    cout << mower_area << endl;
  }

  // Exactly two corners are exposed
  if (bl_covered + tl_covered + tr_covered + br_covered == 2) {

    // TL and BR exposed
    if (tl_covered + br_covered == 0) {
      cout << mower_area - mower_width * (mower_try - cowfeed_try) << endl;
    }
  
    // TR and BR exposed
    if (tr_covered + br_covered == 0) {
      cout << mower_area - mower_height * (cowfeed_trx - mower_blx) << endl;
    }

    // BL and BR exposed
    if (bl_covered + br_covered == 0) {
      cout << mower_area - mower_width * (mower_try - cowfeed_bly) << endl;
    }

    // BL and TL exposed
    if (bl_covered + tl_covered == 0) {
      cout << mower_area - mower_height * (mower_trx - cowfeed_blx) << endl;
    }
  }
  return 0;
}
