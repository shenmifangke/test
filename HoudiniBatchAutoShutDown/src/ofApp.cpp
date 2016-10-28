#include "ofApp.h"
#include <iostream>
#include "windows.h"
#include "tlhelp32.h"
#include "stdio.h"
//--------------------------------------------------------------
HANDLE hProcessSnap;
PROCESSENTRY32 pe32;
bool check = false;
int myTime = 0;
ofImage logo;
void ofApp::setup(){
    ofSetFrameRate(1);

logo.loadImage("logo.png");



}

//--------------------------------------------------------------
void ofApp::update(){
myTime++;

if(myTime>10){
    //��ʹ������ṹǰ�����������Ĵ�С
    pe32.dwSize = sizeof(pe32);
    //��ϵͳ�����еĽ����ĸ�����
    hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
    printf("CreateToolhelp32Snapshot ����ʧ��.\n");
    //return -1;
    }
    //�������̿��գ�������ʾÿ�����̵���Ϣ
    BOOL bMore = ::Process32First(hProcessSnap,&pe32);

    while (bMore)
    {
    //printf("�������ƣ�%ls\n",pe32.szExeFile); //����õ���Ӧ���ǿ��ַ�����%ls,��Ȼ�޷�������ӡ
    //printf("�������ƣ�%s\n",pe32.szExeFile); //����õ���Ӧ���ǿ��ַ�����%ls,��Ȼ�޷�������ӡ

    //printf("����ID��%u\n\n",pe32.th32ProcessID);
    string temp = pe32.szExeFile;
    if(temp == "mantra.exe")
    {
        check = true;
        cout<<temp<<endl;
    }

    bMore = ::Process32Next(hProcessSnap,&pe32);

    }


myTime = 0;
if(check)check = false;
else
{//cout<<"no"<<endl;
system("shutdown -s -t 60");
ofExit(0);
}
}


}
void ofApp::exit(){
//��Ҫ���������snapshot����
::CloseHandle(hProcessSnap);
}

//--------------------------------------------------------------
void ofApp::draw(){
logo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
