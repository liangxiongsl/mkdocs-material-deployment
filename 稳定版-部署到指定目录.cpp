#include<bits/stdc++.h>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <io.h>
#include <windows.h>
#include <wchar.h>

// ��������ת�뺯����Ϊ�˽�� ut8 �� gba2312 ֮���ת��
// ������� mkdocs.yml�����������޷���������ȡ������ 
void Utf8ToGB2312(const char* utf8, char *gb2312)
{
	if (NULL == utf8 || NULL == gb2312) {
		return;
	}

	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t *wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);

	memset(gb2312, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, gb2312, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return;
}

void GB2312ToUtf8(const char* gb2312, char *utf8)
{
	if (NULL == gb2312|| NULL == utf8) {
		return;
	}

	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t *wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);

	memset(utf8, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return;
}

#define f(x) system((string(x)).c_str()) 
char ss[10000], tt[10000];
signed Main(){
	string name;
	cout << "��վ��:\t";
	while(getline(std::cin, name), name.erase(0,name.find_first_not_of(" ")), name.erase(name.find_last_not_of(" ") + 1), name=="");
	puts("���ڴ�conf\\nav.txt...");
	puts("��༭Ŀ¼��(�������xmind)��ճ����conf\\nav.txt");
	puts("!!!���һ�б�������!!!");
	f("conf\\nav.txt");
	
	fstream v("conf/nav.txt", ios::in);
	for(char c; (c=v.get())!=EOF; ){
		if(c == '\\' || c == '/' || c == ':' || c == '*' || c == '?' || c == '\"' || c == '<' || c=='>' || c=='|'){
			std::cout << "conf\nav.txt�а���  " << c << "  !!!\n";
			system("pause");
			return 0;
		}
	}
	v.close();
	
	string s, t; puts("ָ��һ�����Ŀ¼: (�м�ɺ��ո�)");
//	while(getline(std::cin, t), remove(t.begin(), t.end(), ' ') == t.begin()){
//		
//	}
	while(true){
		getline(std::cin, t), t.erase(0,t.find_first_not_of(" ")), t.erase(t.find_last_not_of(" ") + 1);
		if(t != ""){
			if(!access(t.c_str(), 0)) break;
			else cout << "Ŀ¼\"" << t << "\"������" << '\n';
		}
	}
	s = t;
	
	// ������Ŀ 
//	f("mkdocs new " + name);
	
	
	// ����Ŀ¼ 
	fstream cin("conf/tree.txt", ios::in);
	
	string p[10];
	int d = 0;
	#define y !cin.eof()
	for(char c; ; ){
		while(y && (c=cin.get())!='\n' && y){
			p[d] += c;
		}
		if(!y) break;
		string s = ".\\" + name;
		for(int i=1; i<=d; ++i) s += "\\" + p[i];
		f("mkdir \"" + s + "\"");
		
		while(y && (c=cin.get())=='\n'){
			
		}
		if(!y) break;
		
		d = 1;
		while(y && (c=cin.get())=='\t'){
			++ d;
		}
		if(!y) break;
		
		p[d] = c;
	}
	
	cin.close();
	
	// �������ƴ󲿷���Դ�ļ� 
	f("xcopy conf\\dict.txt \"" + name + "\\docs\\res" + "\"");
	f("xcopy conf\\user_dict.txt \"" + name + "\\docs\\res" + "\"");
	f("xcopy conf\\extra.css \"" + name + "\\docs\\res" + "\"");
	f("xcopy conf\\extra.js \"" + name + "\\docs\\res" + "\"");
	f("type nul > \"" + name + "\\docs\\index.md" + "\"");
	f("type nul > \"" + name + "\\includes\\abbr.md" + "\"");
	f("xcopy conf\\main.html \"" + name + "\\overrides" + "\"");
	
	// ���� conf/nav.txt ���� mkdocs.yml�� -nav, ����� site_name = $name 
	// Ȼ��׷�� conf/mkdocs.yml
	// ����� ��վ��/docs/ �´��������½� 
	
	fstream cout(name + "/mkdocs.yml", ios::out);
	cout << "site_name: " + name + "\n";
	cout << "nav: ";
	d = 0;
	cin.open("conf/nav.txt", ios::in);
	for(char c; ;){
		while(y && (c=cin.get())!='\n'){
			if(d) cout << c;
			p[d] += c;
		}
		if(!y) break;
		if(d == 1){
			cout << ":";
//			puts("1");
			f("md \"" + name + "\\docs\\" + p[1] + "\"");
//			puts("1");
		}
		if(d == 2){
//			puts("2");
			cout << ".md";
			f("type nul > \"" + name + "\\docs\\" + p[1] + "\\" + p[2] + ".md" + "\"");
//			std::cout << "type nul > \"" + name + "\\docs\\" + p[1] + "\\" + p[2] + ".md" + "\"" << '\n';
//			puts("2");
		}
		
		cout << c;
		while(y && (c=cin.get())=='\n'){
			cout << c;
		}
		if(!y) break;
		if(d == 1){
//			puts("3");
			cout << "        - " << p[1] << "/index.md\n";
			f("type nul > \"" + name + "\\docs\\" + p[1] + "\\" + "index.md" + "\"");
//			puts("3");
		}
		
		cout << "    ";
		d = 1;
		while(y && (c=cin.get())=='\t'){
//			puts("4");
			cout << "    "; ++ d;
//			puts("4");
		}
		if(!y) break;
		
		p[d] = c;
		if(d == 1){
			cout << "- " << c;
		}
		if(d == 2){
			cout << "- " << p[1] << "/" << c;
		}
	}
	cin.close();
	cout.close();
	f("type conf\\mkdocs.yml >> \"" + name + "\\mkdocs.yml \"");
	
	stringstream ans;
	for(ifstream cin(name+"/mkdocs.yml"); !cin.eof(); ){
		string d;
		getline(cin, d);
		ans << d << '\n';
	}
	
	strcpy(ss, ans.str().c_str());
//	std::cout << ss << '\n';
	GB2312ToUtf8(ss, tt);	std::cout << "GB2312 ת UTF-8 �ɹ�" << '\n';
	
	FILE *fp = fopen((name+"/mkdocs.yml").c_str(), "w");
	fprintf(fp, "%s", tt);
	fclose(fp); 
	
	// 
	f("echo set port=8000>> \"" + name + "\\run.bat" + "\"");
	f("echo start http://localhost:%port% >> \"" + name + "\\run.bat" + "\"");
	f("echo title " + name + " - %port%>> \"" + name + "\\run.bat" + "\"");
	f("echo mkdocs serve -a localhost:%port%>> \"" + name + "\\run.bat" + "\"");
	
	// ����Ŀ�ƶ���ָ����Ŀ¼ 
	cout.open(s);
//	std::cout << "move " + name + " \"" + s + "\"" << '\n';
	f("xcopy /e/q/i \"" + name + "\" \"" + s + "\\" + name + "\"" + " >> log.txt");
	f("rmdir /s/q \"" + name + "\"" + " >> log.txt");
	
	f("echo \"" + s + "\\" + name + "\" >> log.txt");
	f("echo %date% %time% >> log.txt");
	f("echo.>> log.txt");
	
	
	if(!access(("\"" + s + "\\" + name + "\"").c_str(), 0))
		std::cout << "�ɹ�������վ " << name << " ��Ŀ¼ " << s << "\n\n";
	
	
	puts("ok!");
	getchar();
	getchar();
	
//	puts("\n��Ŀ�ṹ:\n");
//	f("tree /f " + name);
//	f(name + "\\mkdocs.yml");
//	f("type " + name + "\\mkdocs.yml");
//	f("rmdir /s /q " + name);
}

signed main(){
	while(true){
		Main();
		system("cls");
	}
}
