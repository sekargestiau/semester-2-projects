#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <stack>

enum node_t {
    RUMAH_PRODUKSI_BAKPIA,
    ALUN_ALUN_KOTA,
    BALAI_KOTA,
    COFFEE_SHOP,
    DESA_WISATA,
    GEDUNG_SERBAGUNA,
    MALL_KOTA,
    TOKO_BANGUNAN,
    PASAR,


    NODE_COUNT,
    NODE_INVALID = -1
};

std::map<node_t, std::string> node_name;

// graph dalam bentuk adjacency matrix
double graph[NODE_COUNT][NODE_COUNT];

void add_edge(node_t src, node_t dst, double weight) {
    graph[src][dst] = weight;
    graph[dst][src] = weight;
}

int main() {
    node_name[RUMAH_PRODUKSI_BAKPIA] = "Rumah Produksi Bakpia";
    node_name[ALUN_ALUN_KOTA] = "Alun-alun Kota";
    node_name[BALAI_KOTA] = "Balai Kota";
    node_name[COFFEE_SHOP] = "Coffee Shop";
    node_name[DESA_WISATA] = "Desa Wisata";
    node_name[GEDUNG_SERBAGUNA] = "Gedung Serbaguna";
    node_name[MALL_KOTA] = "Mall Kota";
    node_name[TOKO_BANGUNAN] = "Toko Bangunan";
    node_name[PASAR] = "Pasar";

    for (int i = 0; i < NODE_COUNT; i++) {
        for (int j = 0; j < NODE_COUNT; j++) {
            if (i == j) {
                graph[i][j] = 0.0;
            } else {
                graph[i][j] = -1.0;
            }
        }
    }

    add_edge(RUMAH_PRODUKSI_BAKPIA, ALUN_ALUN_KOTA, 10.11);
    add_edge(RUMAH_PRODUKSI_BAKPIA, BALAI_KOTA, 9.02);
    add_edge(RUMAH_PRODUKSI_BAKPIA, COFFEE_SHOP, 5.23);
    add_edge(ALUN_ALUN_KOTA, COFFEE_SHOP, 4.07);
    add_edge(ALUN_ALUN_KOTA, DESA_WISATA, 6.87);
    add_edge(BALAI_KOTA, COFFEE_SHOP, 6.10);
    add_edge(BALAI_KOTA, TOKO_BANGUNAN, 6.71);
    add_edge(COFFEE_SHOP, DESA_WISATA, 2.43);
    add_edge(COFFEE_SHOP, TOKO_BANGUNAN, 3.53);
    add_edge(COFFEE_SHOP, GEDUNG_SERBAGUNA, 4.51);
    add_edge(DESA_WISATA, TOKO_BANGUNAN, 2.87);
    add_edge(DESA_WISATA, GEDUNG_SERBAGUNA, 1.32);
    add_edge(DESA_WISATA, PASAR, 7.97);
    add_edge(GEDUNG_SERBAGUNA, MALL_KOTA, 5.41);
    add_edge(GEDUNG_SERBAGUNA, PASAR, 3.25);
    add_edge(TOKO_BANGUNAN, GEDUNG_SERBAGUNA, 4.63);
    add_edge(TOKO_BANGUNAN, MALL_KOTA, 11.02);
    add_edge(PASAR, MALL_KOTA, 9.53);
    

    // himpunan node yang sudah dikunjungi dan belum dikunjungi
    std::set<node_t> visited, unvisited;
    for (int i = 0; i < NODE_COUNT; i++) {
        unvisited.insert((node_t)i);
    }

    // jarak ke node yang bersangkutan
    std::map<node_t, double> path_distance;
    for (int i = 0; i < NODE_COUNT; i++) {
        path_distance[(node_t)i] = INFINITY;
    }

    // parent dari tiap-tiap node
    std::map<node_t, node_t> path_parent;
    for (int i = 0; i < NODE_COUNT; i++) {
        path_parent[(node_t)i] = NODE_INVALID;
    }

    // atur node asal dan tujuan
    node_t node_src = RUMAH_PRODUKSI_BAKPIA;
    node_t node_dst = PASAR;

    // atur supaya node asal dikunjungi pertama kali
    path_distance[node_src] = 0.0;

    while (!unvisited.empty()) {
        // ambil node unvisited dgn jarak terpendek
        node_t pick = NODE_INVALID;
        for (
            std::set<node_t>::iterator it = unvisited.begin();
            it != unvisited.end();
            ++it
        ) {
            if (pick == NODE_INVALID) {
                pick = *it;
            } else {
                if (path_distance[*it] < path_distance[pick]) {
                    pick = *it;
                }
            }
        }

        // tandai sudah dikunjungi
        visited.insert(pick);
        unvisited.erase(pick);

        // cek apabila node tujuan sudah dikunjungi
        // jika sudah langsung berhenti saja
        if (visited.count(node_dst) == 1) {
            break;
        }

        // perbarui jarak-jarak tetangga
        for (int i = 0; i < NODE_COUNT; i++) {
            if ((graph[pick][i] > 0.0) && (unvisited.count((node_t)i) == 1)) {
                // perbarui apabila jarak baru lebih kecil dari jarak sebelumnya
                double distance_old = path_distance[(node_t)i];
                double distance_new = path_distance[pick] + graph[pick][i];
                if (distance_new < distance_old) {
                    path_distance[(node_t)i] = distance_new;
                    path_parent[(node_t)i] = pick;
                }
            }
        }
    }

    // tampilkan rute terpendek
    // menggunakan bantuan stack supaya urutannya sesuai
    double path_shortest_distance = 0.0;
    std::stack<node_t> path_stack;
    for (node_t path = node_dst; path != NODE_INVALID; path = path_parent[path]) {
        path_stack.push(path);
    }
    while (!path_stack.empty()) {
        node_t path = path_stack.top();
        path_stack.pop();

        double weight = 0.0;
        if (path != node_src) {
            weight = graph[path][path_parent[path]];
            path_shortest_distance = path_shortest_distance + weight;
        }

        std::cout << "Path includes node: " << node_name[path] << " (travels " << weight << " units)" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Distance: " << path_shortest_distance << " units" << std::endl;

    return 0;
}
