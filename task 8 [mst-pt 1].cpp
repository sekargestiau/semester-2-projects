#include <iostream>
#include <list>
#include <map>

enum node_t {
    KANTOR_PUSAT_JARINGAN_KOMUNIKASI,
    RUMAH_1,
    RUMAH_2,
    RUMAH_3,
    RUMAH_4,
    RUMAH_5,
    RUMAH_6,
    RUMAH_7,

    NODE_COUNT
};

node_t djs_find(const std::map<node_t, node_t> &rep, node_t element) {
    if (rep.at(element) == element) {
        return element;
    }
    return djs_find(rep, rep.at(element));
}

void djs_union(std::map<node_t, node_t> &rep, node_t a, node_t b) {
    node_t rep_a = djs_find(rep, a);
    node_t rep_b = djs_find(rep, b);
    rep[rep_a] = rep_b;
}

struct edge_t {
    node_t node_src;
    node_t node_dst;
    double weight;

    edge_t(node_t _node_src, node_t _node_dst, double _weight) {
        node_src = _node_src;
        node_dst = _node_dst;
        weight = _weight;
    }
};

bool is_tree(const std::list<edge_t> &graph) {
    // disjoint set
    std::map<node_t, node_t> djs;
    for (int i = 0; i < NODE_COUNT; i++) {
        djs[(node_t)i] = (node_t)i;
    }

    // iterasi seluruh edge
    for (
        std::list<edge_t>::const_iterator it = graph.begin();
        it != graph.end();
        ++it
    ) {
        node_t rep_src = djs_find(djs, it->node_src);
        node_t rep_dst = djs_find(djs, it->node_dst);

        // perwakilan dari kedua node yang dihubungkan edge sama
        // kesimpulan: graf memiliki siklus, bukan tree
        if (rep_src == rep_dst) {
            return false;
        }

        djs_union(djs, rep_src, rep_dst);
    }

    // tidak ada siklus, graf adalah tree
    return true;
}

// sortir graph (edge list) dengan selection sort
std::list<edge_t> sort_edges(std::list<edge_t> graph) {
    std::list<edge_t> sorted;
    while (!graph.empty()) {
        std::list<edge_t>::iterator select = graph.begin();
        for (
            std::list<edge_t>::iterator it = graph.begin();
            it != graph.end();
            ++it
        ) {
            if (it->weight < select->weight) {
                select = it;
            }
        }
        sorted.push_back(*select);
        graph.erase(select);
    }
    return sorted;
}

int main() {
    // graph dalam bentuk edge list
    // masukkan edge sebanyak 1 kali saja supaya MST dapat ter-generate dengan benar
    // berbeda dengan contoh pada materi sebelumnya yang mana tiap edge dimasukkan dua kali termasuk dari arah yang berlawanan
    std::list<edge_t> graph;
    graph.push_back(edge_t(KANTOR_PUSAT_JARINGAN_KOMUNIKASI, RUMAH_1, 2.01));
    graph.push_back(edge_t(KANTOR_PUSAT_JARINGAN_KOMUNIKASI, RUMAH_2, 4.04));
    graph.push_back(edge_t(RUMAH_1, RUMAH_2, 1.01));
    graph.push_back(edge_t(RUMAH_1, RUMAH_3, 3.02));
    graph.push_back(edge_t(RUMAH_1, RUMAH_4, 2.03));
    graph.push_back(edge_t(RUMAH_2, RUMAH_3, 1.04));
    graph.push_back(edge_t(RUMAH_2, RUMAH_6, 4.01));
    graph.push_back(edge_t(RUMAH_3, RUMAH_4, 1.02));
    graph.push_back(edge_t(RUMAH_3, RUMAH_5, 2.02));
    graph.push_back(edge_t(RUMAH_3, RUMAH_6, 2.04));
    graph.push_back(edge_t(RUMAH_4, RUMAH_5, 3.01));
    graph.push_back(edge_t(RUMAH_4, RUMAH_7, 2.12));
    graph.push_back(edge_t(RUMAH_5, RUMAH_6, 3.03));
    graph.push_back(edge_t(RUMAH_6, RUMAH_7, 3.04));



    // sortir berdasarkan bobot
    graph = sort_edges(graph);

    // minimum spanning tree
    std::list<edge_t> mst;
    while (mst.size() < (NODE_COUNT - 1)) {
        edge_t pick = graph.front();
        graph.pop_front();

        // ambil edge dgn bobot terendah
        mst.push_back(pick);
        if (!is_tree(mst)) {
            // ada siklus, edge tidak jadi diambil
            mst.pop_back();
        }
    }

    double mst_weight = 0.0;
    for (
        std::list<edge_t>::iterator it = mst.begin();
        it != mst.end();
        ++it
    ) {
        std::cout << "MST includes edge: " << it->weight << std::endl;
        mst_weight = mst_weight + it->weight;
    }
    std::cout << std::endl;
    std::cout << "MST total weight: " << mst_weight << std::endl;

    return 0;
}
