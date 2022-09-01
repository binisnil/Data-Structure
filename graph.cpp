//
// Created by 박윤빈 on 2022/06/03.
//

#include "graph.h"
#include <iostream>
#include <string>
using namespace std;
void Graph::LoadMatrix(std::string& filename){

    std::ifstream fin;
    fin.open(filename);

    fin>>vertex;


    for(int i=0;i<vertex;i++){
        for (int j = 0; j < vertex; j++) {
            fin>> Weight[i][j];
        }
    }
}

void Graph::PrintMatrix() {
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<Weight[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Graph::GetSize() {
    return vertex;
}


int Graph::FindShortNode(){

    int Min_Dist = 999;
    int Min_Idx = 0;

    for (int i = 0; i < vertex; i++) {
       // if (Select[i] == true) continue;

        if (Dist[i] < Min_Dist && !Select[i]) {//시작 정점과 i번째 정점이 연결되어 있다면
            Min_Dist = Dist[i]; //최단거리(가장 작은 가중치)는 Dist i이다.
            Min_Idx = i; //시작 정점과 연결된 정점 중 가중치가 가장 작은 정점을 설정
        }
    }
    return Min_Idx;
}


void Graph::Dijkstra(int s) {
    initialization();
    for (int i = 0; i < vertex; i++)
        Dist[i] = Weight[s][i]; //시작노드와 연결된 모든 정점들의 거리를 업데이트

    Select[s] = true;


    for(int i=0;i<vertex-1;i++){
        newnode=FindShortNode();
        Select[newnode]=true;

        for(int i=0;i<vertex;i++) {
            if (!Select[i]) {
                if (Dist[newnode] + Weight[newnode][i] < Dist[i])
                    Dist[i] = Dist[newnode] + Weight[newnode][i];
            }
        }
    }
}

void Graph::PrintShortestPathWeight(int s) { //s=시작정점
    Dijkstra(s);
    for(int i=0;i<vertex;i++){
        cout<<Dist[i]<<endl;
    }
}

void Graph::initialization() {
    for(int i=0;i<vertex;i++){
        Dist[i]=0;
        Select[i]= false;
    }
}

void Graph::graphsearch(int startvertex) {
    for (int i = 0; i < vertex; ++i) {
        Dist[i] = Weight[startvertex][i];
    }
    Dist[startvertex] = 0;
    Select[startvertex] = true;

    // 시작 정점일 때, 이전 정점의 값을 세팅하는 지점
    formerVisitedVertex[startvertex] = -1;

    for (int i = 0; i < vertex - 1; ++i) {
        int currentVertexNumber = FindShortNode();
        Select[currentVertexNumber] = true;

        for (int j = 0; j < vertex; ++j) {
            if (!Select[j]) {
                if (Dist[j] >
                    Dist[currentVertexNumber] +
                    Weight[currentVertexNumber][j]) {

                    formerVisitedVertex[j] = currentVertexNumber;

                    Dist[j] =
                            Dist[currentVertexNumber] +
                            Weight[currentVertexNumber][j];
                }
            }
        }
    }
}

void Graph::SettingRoute(int finalVertex, int vertexNumber) {
    if (formerVisitedVertex[vertexNumber] == -1) {
       cout<<vertexNumber<<" ";
        return;
    } else {
        SettingRoute(finalVertex, formerVisitedVertex[vertexNumber]);
        cout<<vertexNumber<<" ";
    }
}

void Graph::PrintShortestPath(int s) {
    this->graphsearch(s);

    for (int i = 1; vertex > i; ++i) {
        SettingRoute(i, i);
        cout << endl;
    }
}

//최지웅 학생의 도움을 받아 코드를 작성하였습니다.