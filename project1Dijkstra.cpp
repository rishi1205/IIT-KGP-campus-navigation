#include <iostream>
#include <climits>
#include <string>
using namespace std;

#define V 22

int minDistance(int distance[], bool vis[]) {
    int mini = INT_MAX;
    int idx = -1;

    for(int i = 1; i < V; i++) {
        if(!vis[i] && distance[i] < mini) {
            mini = distance[i];
            idx = i;
        }
    }

    return idx;
}

void printPath(int parents[], string place[], int curr) {
    if(parents[curr] == -1) {
        cout << place[curr];
        return;
    }

    printPath(parents, place, parents[curr]);

    cout << " -> " << place[curr];
}

void dijkstra(int graph[V][V], int source , int destination, string place[]) {
    int distance[V];
    bool vis[V];
    int parents[V];

    for(int i = 1; i < V; i++) {
        distance[i] = INT_MAX;
        vis[i] = false;
        parents[i] = -1;
    }

    distance[source] = 0;

    for(int cnt = 0; cnt < V-1; cnt++) {
        int u = minDistance(distance, vis);

        if(u == -1) break;

        vis[u] = true;
        for(int v = 1; v < V; v++) {
            if(!vis[v] &&
               graph[u][v] &&
               distance[u] != INT_MAX &&
               distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];
                parents[v] = u;
            }
        }
    }

    cout << "\n====================================";
    cout << "\nSOURCE      : " << place[source];
    cout << "\nDESTINATION : " << place[destination];
    cout << "\n====================================\n";

    if(distance[destination] == INT_MAX)
    {
        cout << "\nNo path exists!\n";
        return;
    }

    // Print shortest distance
    cout << "\nShortest Distance = "
         << distance[destination]
         << " meters\n";

    // Print shortest route
    cout << "\nShortest Route:\n\n";

    printPath(parents, place, destination);

    cout << "\n";
}

int main() {
    string place[V] =
    {
        "",
        "Main Gate",                // 1
        "Central Library",          // 2
        "Vikramshila",              // 3
        "Takshashila",              // 4
        "Nalanda",                  // 5
        "Netaji Auditorium",        // 6
        "Kalidas Auditorium",       // 7
        "Gymkhana",                 // 8
        "BC Roy Hospital",          // 9
        "Nehru Hall",               // 10
        "Azad Hall",                // 11
        "Patel Hall",               // 12
        "LBS Hall",                 // 13
        "MMM Hall",                 // 14
        "RP Hall",                  // 15
        "RK Hall",                  // 16
        "HJB Hall",                 // 17
        "LLR Hall",                 // 18
        "JCB Hall",                 // 19
        "Tata Sports Complex",      // 20
        "Hijli Gate"                // 21
    };

    //--------------------------------------------------
    // Adjacency Matrix
    // graph[i][j] = distance between locations
    //--------------------------------------------------
    int graph[V][V] = {0};

    //--------------------------------------------------
    // Campus Road Network
    //--------------------------------------------------

    // Main Gate ↔ Central Library
    graph[1][2] = graph[2][1] = 500;

    // Main Gate ↔ Hijli Gate
    graph[1][21] = graph[21][1] = 600;

    // Academic Zone
    graph[2][3] = graph[3][2] = 350;
    graph[3][4] = graph[4][3] = 200;
    graph[4][5] = graph[5][4] = 300;

    // Direct connection to Gymkhana
    graph[2][8] = graph[8][2] = 500;

    // Auditoriums
    graph[2][6] = graph[6][2] = 150;
    graph[3][7] = graph[7][3] = 100;
    graph[6][7] = graph[7][6] = 200;

    // Sports Area
    graph[8][20] = graph[20][8] = 400;

    // Hospital
    graph[20][9] = graph[9][20] = 300;

    // Hostel Connections
    graph[9][10] = graph[10][9] = 200;
    graph[9][11] = graph[11][9] = 250;
    graph[9][12] = graph[12][9] = 300;
    graph[9][13] = graph[13][9] = 350;
    graph[9][14] = graph[14][9] = 200;
    graph[9][15] = graph[15][9] = 250;
    graph[9][16] = graph[16][9] = 300;
    graph[9][17] = graph[17][9] = 350;
    graph[9][18] = graph[18][9] = 400;
    graph[9][19] = graph[19][9] = 450;

    //--------------------------------------------------
    // Display Campus Locations
    //--------------------------------------------------
    cout << "\n====================================";
    cout << "\n     IIT KHARAGPUR NAVIGATION";
    cout << "\n====================================\n";

    cout << "\nAvailable Locations:\n\n";

    for(int i = 1; i < V; i++)
    {
        cout << i << ". " << place[i] << endl;
    }

    //--------------------------------------------------
    // Take User Input
    //--------------------------------------------------
    int source, destination;

    cout << "\nEnter Source Location Number: ";
    cin >> source;

    cout << "Enter Destination Location Number: ";
    cin >> destination;

    //--------------------------------------------------
    // Validate Input
    //--------------------------------------------------
    if(source < 1 || source >= V ||
       destination < 1 || destination >= V)
    {
        cout << "\nInvalid Location Number!\n";
        return 0;
    }

    //--------------------------------------------------
    // Run Dijkstra Algorithm
    //--------------------------------------------------
    dijkstra(graph, source, destination, place);

    return 0;
}
