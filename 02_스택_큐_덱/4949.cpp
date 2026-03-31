// ① 반복문으로 getline을 이용해서 줄바꿈전까지, 즉, 한 문장씩 s에 저장되어서 읽도록 한다.
// ② 스택에 입력 받을 때: 반복문으로 괄호가 나오면 그 괄호만 저장하는 스택을 만든다. -> 일단 왼괄호면 일단 저장을 한다. 
// ③ 그리고 오괄호가 나오면 왼괄호만 저장된 스택에서 top을 오괄호와 비교해서 매칭이 되면 매칭된 왼괄호를 스택에서 지운다.
// ④ getline이 끝난 뒤 스택이 empty하다면 yes. 아니라면 no를 출력하기
// ⑤ getline의 s가 그냥 "."이라면 break;을 한다.

// string을 바로 스택에 넣지 않고 char로 넣는다. -> getline(cin,s) : 입력에서 줄바꿈전까지 모두 읽어서 s에 저장한다. 
// 그리고 for (char c : s)로 문자열에서 하나씩 꺼내서 쓴다. 혹은 풀어서 쓸 수도 있다. 

#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  stack<char> st;
  string s;

  while(true){
    getline(cin,s); //1
    bool isValid = true;

    if( s == "."){
      break;
    }

    for (int i=0; i<s.size(); i++){
      char c = s[i];
    
      if(c == '[' or c == '('){ //쌍따옴표 금지!
        st.push(c);
      }
      else if (c == ')'){
        if (st.empty() || st.top() != '('){
          isValid = false;
          break;
        }
        else{
          st.pop();
        }
      }
      else if (c == ']'){
        if(st.empty() || st.top() != '['){
          isValid = false;
          break;
        }
        else {
          st.pop();
        }
      }
    }

    if(isValid == true && st.empty()){
        cout <<"yes" << "\n";
      }
    else {
      cout << "no" << "\n";
    }

    int size = st.size();

    for (int j=0; j<size; j++){
        st.pop();
      }
  }

}
