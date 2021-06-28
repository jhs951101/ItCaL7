#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	cout << "Enter a file name: ";
	string file;                   // file: ���� �̸��� �Է¹ޱ� ���� string ����
	cin >> file;                   // ���� �̸� �Է� �ޱ�

	ifstream ifs;                  // ifs: ���� ��ü ����
	ifs.open(file);                // ������ ��ũ��

	char ch;                       // ch: �ؽ�Ʈ ������ ���ڸ� �ϳ��� �����ϱ� ���� ����
	int decide=0;                  // decide: ��ȣ�� �´��� �ȸ´����� �Ǵ��ϱ� ���� ����
	int line=1;                    // line: �ؽ�Ʈ n�� (n=line)

	while(ifs.get(ch)){            // ifs.get(ch): �ؽ�Ʈ ������ ���ڸ� ������� �ϳ��� ch�� ������

		if(ch=='(') decide++;
		if(ch==')') decide--;      // ��ȣ�� �´��� �ȸ´����� �Ǵ��ϱ� ���� ���

		if(ch==';'){
			if(decide>0) cout << "Too many left parentheses at the line " << line << "\n";
			if(decide<0) cout << "Too many right parentheses at the line " << line << "\n";
			decide=0;
		}                          // ��ȣ�� �´��� �ȸ´��� �Ǵ� (;)
		if(ch=='{'){
			if(decide>0) cout << "Too many left parentheses at the line " << line << "\n";
			if(decide<0) cout << "Too many right parentheses at the line " << line << "\n";
			decide=0;
		}                          // ��ȣ�� �´��� �ȸ´��� �Ǵ� ({)

		if(ch=='\n') line++;       // �� ���� �������Ƿ� n+1 (n=line)

	}

  return 0;
}