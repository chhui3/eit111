struct vec {
    int x;
    int y;
    vec& operator+(const vec& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
};
//vec operator+(vec& a, vec& b) {
//    return vec{ a.x + b.x, a.y + b.y };
//}


vec add(vec a, vec b) {
    return vec{ a.x + b.x, a.y + b.y };
}

int main() {
    vec a{ 10,10 };
    vec b{ 20,20 };
    vec c = add(a, b);
    vec d = a + b;
    return 0;
}
