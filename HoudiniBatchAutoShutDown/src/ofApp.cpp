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
    //在使用这个结构前，先设置它的大小
    pe32.dwSize = sizeof(pe32);
    //给系统内所有的进程拍个快照
    hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
    printf("CreateToolhelp32Snapshot 调用失败.\n");
    //return -1;
    }
    //遍历进程快照，轮流显示每个进程的信息
    BOOL bMore = ::Process32First(hProcessSnap,&pe32);

    while (bMore)
    {
    //printf("进程名称：%ls\n",pe32.szExeFile); //这里得到的应该是宽字符，用%ls,不然无法正常打印
    //printf("进程名称：%s\n",pe32.szExeFile); //这里得到的应该是宽字符，用%ls,不然无法正常打印

    //printf("进程ID：%u\n\n",pe32.th32ProcessID);
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
//不要忘记清除掉snapshot对象
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
