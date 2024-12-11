#include "Base.hpp"

int main() {
    // generate()でランダムなBase型のインスタンスを作成
    Base* p = generate();

    // ポインタで識別
    identify(p);

    // 参照で識別
    identify(*p);

    // メモリ解放
    delete p;

    return 0;
}