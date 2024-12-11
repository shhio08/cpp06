#include "Serializer.hpp"

int main() {
    // Data オブジェクトを作成
    Data data;
	data.value = 42;

    // そのポインタをシリアライズ
    uintptr_t raw = Serializer::serialize(&data);

    // シリアライズした値をデシリアライズしてポインタを取得
    Data* deserializedData = Serializer::deserialize(raw);

    // デシリアライズされたポインタが元のポインタと一致するか確認
    if (&data == deserializedData) {
        std::cout << "Success: The pointers are the same!" << std::endl;
    } else {
        std::cout << "Failure: The pointers are different!" << std::endl;
    }

    return 0;
}