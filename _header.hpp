#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::pair<ll, ll> p64;
typedef std::vector<ll> v64;
typedef std::vector<std::vector<ll>> vv64;
typedef std::vector<p64> vp64;

const bool DEB = true;
const ll MOD = 1e9 + 7;
#define deb(x)                                                                 \
  std::cerr << #x << " : ";                                                    \
  _print(x);                                                                   \
  std::cerr << std::endl
#define ff(i, a, n) for (int i = (a); i < (n); i++)
#define fb(i, a, n) for (int i = (a); i >= (n); i--)

class TikTik {
private:
  std::chrono::_V2::system_clock::time_point timestamp;
  double timeTaken;

public:
  TikTik() { timeTaken = -1; }

  void tik() {
    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;
    timestamp = high_resolution_clock::now();
  }

  double tok() {
    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;
    std::chrono::_V2::system_clock::time_point endtime =
        high_resolution_clock::now();
    duration<double, std::milli> ms_double = endtime - timestamp;
    timeTaken = ms_double.count();
    return ms_double.count();
  }

  void print_time_taken() {
    std::cout << "Time taken: " << timeTaken << "ms" << std::endl;
  }

  void sleep_for_10ms() {
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    sleep_for(10ms);
  }
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL){};
};

struct DLListNode {
  int val;
  DLListNode *next;
  DLListNode *prev;
  DLListNode(int x) : val(x), next(NULL), prev(NULL){};
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void _print(TreeNode *root);

void _print(ll x) { std::cerr << x; }
void _print(std::string x) { std::cerr << x; }

template <class T, class V> void _print(std::pair<T, V> p) {
  std::cerr << " {";
  _print(p.first);
  std::cerr << ",";
  _print(p.second);
  std::cerr << "}";
}
template <class T> void _print(std::vector<T> v) {
  std::cerr << " [";
  for (T i : v) {
    _print(i);
    std::cerr << " ";
  }
  std::cerr << "]";
}
template <class T> void _print(std::set<T> v) {
  std::cerr << " [";
  for (T i : v) {
    _print(i);
    std::cerr << " ";
  }
  std::cerr << "]";
}
template <class T> void _print(std::multiset<T> v) {
  std::cerr << " [";
  for (T i : v) {
    _print(i);
    std::cerr << " ";
  }
  std::cerr << "]";
}
template <class T, class V> void _print(std::map<T, V> v) {
  std::cerr << " [";
  for (auto i : v) {
    _print(i);
    std::cerr << " ";
  }
  std::cerr << "]";
}
template <class T> void _print(std::deque<T> dq) {
  std::cerr << " [";
  for (auto i : dq) {
    _print(i);
    std::cerr << " ";
  }
  std::cerr << "]";
}
template <class T> void _print(std::list<T> li) {
  std::cerr << " [";
  for (auto it : li) {
    _print(it);
    std::cerr << " ";
  }
  std::cerr << "] ";
}
template <class T> void _print(std::stack<T> st) {
  std::cerr << " ";
  while (st.size()) {
    std::cerr << st.top() << "->" << st.top()->val << " ";
    st.pop();
  }
  std::cerr << "]";
}

ll powmod(ll base, ll exp) {
  ll ans = 1;
  while (exp) {
    if (exp & 1)
      ans = (ans * base) % MOD;
    base = (base * base) % MOD;
    exp /= 2;
  }
  return ans;
}

template <class T> void print_bits(T a) {
  std::vector<bool> bits(8 * sizeof(T));
  ff(i, 0, bits.size()) {
    bits[i] = a & 1;
    a = a >> 1;
  }
  fb(i, bits.size(), 0) std::cout << bits[i];
  std::cout << "\n";
}

void _print(DLListNode *head) {
  // check if it is head or tail
  if (head->next == NULL) {
    // tail
    std::cerr << "TAIL ";
    while (head != NULL) {
      std::cerr << head->val << "<=>";
      head = head->prev;
    }
  } else {
    std::cerr << "HEAD ";
    while (head != NULL) {
      std::cerr << head->val << "<=>";
      head = head->next;
    }
  }
  std::cerr << "NULL\n";
}

void _print(ListNode *head) {
  while (head) {
    std::cerr << head->val << "->";
    head = head->next;
  }
  std::cerr << "\n";
}

ListNode *arr2LL(vi &arr) {
  ListNode *head = NULL;
  for (int i = arr.size() - 1; i >= 0; i--) {
    ListNode *tmp = new ListNode(-1);
    tmp->val = arr[i];
    tmp->next = head;
    head = tmp;
  }
  return head;
}

std::pair<DLListNode *, DLListNode *> arr2DLL(vi &arr) {
  DLListNode *head, *tail = NULL;
  if (arr.size() < 1)
    return std::make_pair((DLListNode *)NULL, (DLListNode *)NULL);
  head = new DLListNode(arr[0]);
  head->next = NULL;
  head->prev = NULL;
  tail = head;
  for (int i = 1; i < (int)arr.size(); i++) {
    DLListNode *tmp = new DLListNode(arr[i]);
    tmp->prev = tail;
    tmp->next = NULL;
    tail->next = tmp;
    tail = tmp;
  }
  return std::make_pair(head, tail);
}

void printBTree(TreeNode *node, int space) {
  if (node == NULL)
    return;
  space += 4;
  printBTree(node->right, space);
  ff(i, 0, space) std::cerr << " ";
  std::cerr << node->val << "\n";
  printBTree(node->left, space);
}

void _print(TreeNode *root) {
  std::cerr << "\n";
  printBTree(root, 0);
}

TreeNode *getNewTreeNode(int data) {
  TreeNode *tmp = new TreeNode(data);
  tmp->left = tmp->right = NULL;
  return tmp;
}

void InsertBST(TreeNode *&root, int data) {
  if (root == NULL) {
    root = getNewTreeNode(data);
  } else {
    if (data <= root->val) {
      InsertBST(root->left, data);
    } else {
      InsertBST(root->right, data);
    }
  }
}

/*
Put idx = 1
*/
TreeNode *buildTreeFromArr(vi arr, TreeNode *root, int idx) {
  if (arr[idx] == -1)
    return NULL;
  if (idx > (int)arr.size() - 1)
    return NULL;
  root = new TreeNode(arr[idx]);
  root->left = buildTreeFromArr(arr, root->left, 2 * idx);
  root->right = buildTreeFromArr(arr, root->right, 2 * idx + 1);
  return root;
}
