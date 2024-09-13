#include <iostream>
#include <vector>
#include "utils/bitset.h"

void Test1() {
  dynamic_bitset bitset(100009);
  std::vector<bool> answer;
  answer.resize(100009);
  for (int i = 2; i * i < 100009; ++i) {
    if (!bitset[i]) {
      for (int j = i; i * j < 100009; ++j) {
        bitset[i * j] = true;
      }
    }
    if (!answer[i]) {
      for (int j = i; i * j < 100009; ++j) {
        answer[i * j] = true;
      }
    }
  }
  dynamic_bitset check1 = bitset;
  bitset.reset();
  for (int i = 2; i < 100009; ++i) {
    assert(answer[i] == check1[i]);
  }
  assert(check1.count() == 100009 - 9593 - 2);
  assert(!check1.all());
  assert(check1.any());
  assert(!check1.none());
  assert(bitset.count() == 0);
  assert(!bitset.any());
  assert(bitset.none());
  assert(!bitset.all());
  for (int i = 2; i * i < 100009; ++i) {
    if (!bitset.test(i)) {
      for (int j = i; i * j < 100009; ++j) {
        bitset.set(i * j);
      }
    }
  }
  dynamic_bitset check2 = std::move(bitset);
  for (int i = 2; i < 100009; ++i) {
    assert(answer[i] == check2.test(i));
    assert(!answer[i] == ~check2[i]);
  }
  assert(check2.count() == 100009 - 9593 - 2);
  check2.flip();
  assert(check2.count() == 9593 + 2);
  assert(!check2.all());
  assert(check2.any());
  assert(!check2.none());
}

void Test2() {
  dynamic_bitset bitset1(100000);
  dynamic_bitset bitset2(100000);
  for (int i = 0; i < 100000; ++i) {
    if (i % 3 == 0) {
      bitset1.set(i);
    }
    if (i % 5 == 0) {
      bitset2.set(i);
    }
  }
  auto ans1 = bitset1 - bitset2;
  for (int i = 0; i < 100000; ++i) {
    if (i % 3 == 0 && i % 5 != 0) {
      assert(ans1.test(i));
    } else {
      assert(!ans1[i]);
    }
  }
  auto ans2 = bitset1 & bitset2;
  for (int i = 0; i < 100000; ++i) {
    if (i % 3 == 0 && i % 5 == 0) {
      assert(ans2.test(i));
    } else {
      assert(!ans2[i]);
    }
  }
  auto ans3 = bitset1 | bitset2;
  for (int i = 0; i < 100000; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      assert(ans3.test(i));
    } else {
      assert(!ans3[i]);
    }
  }
  auto ans4 = bitset1 ^ bitset2;
  for (int i = 0; i < 100000; ++i) {
    if (i % 3 == 0 && i % 15 != 0 || i % 5 == 0 && i % 15 != 0) {
      assert(ans4.test(i));
    } else {
      assert(!ans4[i]);
    }
  }
  auto ans5 = ~bitset1;
  for (int i = 0; i < 100000; ++i) {
    if (i % 3 != 0) {
      assert(ans5.test(i));
    } else {
      assert(!ans5[i]);
    }
  }
}

void Test3() {
  dynamic_bitset bitset1(200039);
  for (int i = 0; i < 200039; ++i) {
    bitset1.reset();
    assert(bitset1.count() == 0);
    assert(!bitset1.all());
    assert(!bitset1.any());
    assert(bitset1.none());
    bitset1.set(i);
    assert(bitset1.count() == 1);
    assert(!bitset1.all());
    assert(bitset1.any());
    assert(!bitset1.none());
  }
  dynamic_bitset bitset2 = bitset1;
  bitset1.reset();
  for (int i = 0; i < 200039; ++i) {
    bitset2.set(i);
  }
  assert(bitset1.count() == 0);
  assert(!bitset1.all());
  assert(!bitset1.any());
  assert(bitset1.none());
  assert(bitset2.count() == 200039);
  assert(bitset2.all());
  assert(bitset2.any());
  assert(!bitset2.none());
  dynamic_bitset bitset3(200039);
  bitset3.set();
  assert(bitset3.count() == 200039);
  assert(bitset3.all());
  assert(bitset3.any());
  assert(!bitset3.none());
}

int main() {
  Test1();
  Test2();
  Test3();
}