// Jawaban Soal Nomor 1
#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int m_data;
    vector<Node> m_children;
    
    Node(int data){
        m_data = data;
    }

    void setData(int data){
        m_data = data;
    }

    void insert(Node node){
        m_children.push_back(node);
    }

    bool DeleteNodeIndex(unsigned int index){
        if(m_children.empty()){
            return false;
        }else{
            if(m_children.size() <= index){
                return false;
            }else{
                m_children.erase(m_children.begin() + index);
                return true;
            }
        }
    }

    void PreOrderTree(unsigned int depth = 0){
        for(unsigned int i = 0; i < depth; i++){
            cout << "--";
        }
        cout << "> " << m_data << '\n';
        for(unsigned int i = 0; i < m_children.size(); i++){
            m_children[i].PreOrderTree(depth + 1);
        }
    }

    void ShowPreOrderTree(){
        cout << "PreOrder Traversal : \n";
        PreOrderTree();
    }

    void PostOrderTree(unsigned int depth = 0){
        for(unsigned int i = 0; i < m_children.size(); i++){
            m_children[i].PostOrderTree(depth + 1);
        }
        
        for(unsigned int i = 0; i < depth; i++){
            cout << "--";
        }
        cout << "> " << m_data << '\n';
    }

    void ShowPostOrderTree(){
        cout << "PostOrder Traversal : \n";
        PostOrderTree();
    }
};


int main(){
    Node root(6);

    Node child_1_0(2); 
    Node child_1_1(3);
    Node child_1_2(7);
    Node child_1_3(11);

    Node child_2_0(2);
    Node child_2_1(4);
    Node child_2_2(1);
    Node child_2_3(9);
    Node child_2_4(6);

    Node child_3_0(12);
    Node child_3_1(5);
    Node child_3_2(5);
    Node child_3_3(10);

    Node child_4_0(8);

    child_3_2.insert(child_4_0);

    child_2_0.insert(child_3_0);
    child_2_0.insert(child_3_1);
    child_2_0.insert(child_3_2);
    child_2_0.insert(child_3_3);

    child_1_0.insert(child_2_0);

    child_1_1.insert(child_2_1);
    child_1_1.insert(child_2_2);
    child_1_1.insert(child_2_3);

    child_1_3.insert(child_2_4);

    root.insert(child_1_0);
    root.insert(child_1_1);
    root.insert(child_1_2);
    root.insert(child_1_3);

    cout << "\n";
    root.ShowPreOrderTree();
    cout << "\n";
    root.ShowPostOrderTree();
    cout << "\n";

    // Jawaban Soal Nomor 2
    root.m_children[0].DeleteNodeIndex(0);

    Node child_2_5(3);

    Node child_3_4(1);
    Node child_3_5(7);
    Node child_3_6(8);

    root.m_children[3].m_children[0].insert(child_3_4);
    root.m_children[3].m_children[0].insert(child_3_5);
    root.m_children[3].m_children[0].insert(child_3_6);

    root.m_children[0].insert(child_2_5);
    
    cout << "[Soal Nomor 2 - Setelah dilakukan deletion dan insertion pada Tree]\n" << endl;
    root.ShowPreOrderTree();
    cout << "\n";
    root.ShowPostOrderTree();
    cout << "\n";

    return 0;
}



/*
JAWABAN PERTANYAAN TANTANGAN :
1. Ada banyak jenis struktur data Tree yang mungkin memiliki peraturan yang berbeda-beda dalam pembuatan nodenya. Apa sajakah contohnya?
   Jawab:
   Contoh Struktur data Tree, yaitu :
   a. Binary Tree
      Binary Tree adalah tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua subtree dan kedua subtree tersebut harus terpisah. 
      Selanjutnya, Binary tree terbagi menjadi beberapa jenis, yaitu :
      - Full Binary Tree
        Full Binary Tree adalah jenis binary tree yang tiap nodenya (kecuali leaf) memiliki dua child dan tiap subtree harus mempunyai panjang path yang sama.
      - Complete Binary Tree
        Full Binary Tree adalah jenis binary tree yang tiap subtreenya boleh memiliki panjang path yang berbeda dan setiap node (kecuali leaf) hanya boleh memiliki 2 child.
      - Skewed Binary Tree
        Skewed Binary Tree adalah jenis binary tree yang semua nodenya (kecuali leaf) hanya memiliki satu child.
    b. Binary Search Tree
       Binary Search Tree adalah struktur data yang mengadopsi konsep Binary Tree namun terdapat aturan bahwa setiap child node sebelah kiri memiliki nilai yang lebih kecil daripada root node dan setiap child node sebelah kanan memiliki nilai yang lebih besar daripada root node.

2. Mengapa kita melakukan insert dari bawah? Mengapa kita tidak melakukan insert mulai dari root? 
   Apa yang terjadi jika kita melakukan insert mulai dari root? Mengapa hal itu bisa terjadi?
   Jawab : Kita melakukan insert dari bawah karena untuk menjaga balance dari tree atau menjaga ketinggiannya (jumlah maksimum level di bawah akar) kecil dalam menghadapi operasi penyisipan (insertion) dan penghapusan (deletion) item yang dilakukan pada Tree.
   Ketinggian biasanya dipertahankan dalam urutan Log n sehingga semua operasi memakan waktu rata-rata O(Log n). Apabila insert dilakukan dari root maka kemungkinan operasinya akan memakan waktu rata-rata yang lebih lama daripada ketika melakukan insert dari bawah/leaf.
   
*/
