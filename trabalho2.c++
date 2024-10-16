#include <iostream>
using namespace std;

struct No {
  int valor;
  No* proximo;

  No(int v) : valor(v), proximo(nullptr) {}
};

No* topo = nullptr;

void empilhar(int valor) {
  No* novoNo = new No(valor);
  novoNo -> proximo = topo;
  topo = novoNo;
  cout << "Adicionado: " << valor << endl;
};

int desempilhar() {
  if (topo == nullptr) {
    cout << "Pilha vazia!" << endl;
    return -1;
  }
  int valorRemovido = topo -> valor;
  No* temp = topo;
  topo = topo -> proximo;
  delete temp;
  cout << "Removido: " << valorRemovido << endl;
  return valorRemovido;
}

bool vazia() {
    return topo == nullptr;
}

void imprimirPilha() {
    if (vazia()) {
        cout << "Pilha vazia!" << endl;
        return;
    }
    
    No* atual = topo;
    cout << "Pilha: ";
    while (atual != nullptr) {
      cout << atual->valor << " ";
      atual = atual->proximo;
    }
    cout << endl;
}

int main() {

  empilhar(5);
  empilhar(10);
  empilhar(15);

  imprimirPilha();

  desempilhar();
  desempilhar();
  desempilhar();
  desempilhar();

  return 0;
}
