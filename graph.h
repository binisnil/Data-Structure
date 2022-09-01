//
// Created by 박윤빈 on 2022/06/03.
//

#ifndef GRAPH_RE_GRAPH_H
#define GRAPH_RE_GRAPH_H
#include <iostream>
#include <fstream>
#include <string>
class Graph{

public:

    int vertex;
    int Weight[999][999] ;
    bool Select[999]; //방문한 정점
    int Dist[999]; //각 정점까지 가는데 드는 최소비용
    int newnode;
    int formerVisitedVertex[999];
    int visitedVertexRoute[999][999];
    void LoadMatrix(std::string& filename);
    void PrintMatrix();
    //void UpdateDist(int New);
    int FindShortNode();
    void Dijkstra(int s);
    int GetSize(); //행렬의 크기 반환 (n x n의 경우 n 반환)
    void PrintShortestPathWeight(int s); // 시작 정점 s로부터 나머지 vertex까지의 최단 경로 출력
    void initialization();
    void PrintShortestPath(int s);
    void graphsearch(int startvertex);
    void SettingRoute(int finalVertex, int vertexNumber);
};
#endif //GRAPH_RE_GRAPH_H
