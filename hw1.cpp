#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	cout << "Enter a file name: ";
	string file;                   // file: 파일 이름을 입력받기 위한 string 변수
	cin >> file;                   // 파일 이름 입력 받기

	ifstream ifs;                  // ifs: 파일 자체 변수
	ifs.open(file);                // 파일을 링크함

	char ch;                       // ch: 텍스트 파일의 문자를 하나씩 저장하기 위한 변수
	int decide=0;                  // decide: 괄호가 맞는지 안맞는지를 판단하기 위한 변수
	int line=1;                    // line: 텍스트 n행 (n=line)

	while(ifs.get(ch)){            // ifs.get(ch): 텍스트 파일의 문자를 순서대로 하나씩 ch에 저장함

		if(ch=='(') decide++;
		if(ch==')') decide--;      // 괄호가 맞는지 안맞는지를 판단하기 위해 사용

		if(ch==';'){
			if(decide>0) cout << "Too many left parentheses at the line " << line << "\n";
			if(decide<0) cout << "Too many right parentheses at the line " << line << "\n";
			decide=0;
		}                          // 괄호가 맞는지 안맞는지 판단 (;)
		if(ch=='{'){
			if(decide>0) cout << "Too many left parentheses at the line " << line << "\n";
			if(decide<0) cout << "Too many right parentheses at the line " << line << "\n";
			decide=0;
		}                          // 괄호가 맞는지 안맞는지 판단 ({)

		if(ch=='\n') line++;       // 한 행이 끝났으므로 n+1 (n=line)

	}

  return 0;
}