

while (true) {
    bool count = false;
    char prev = '1';

    while (!pila[idx].empty()) {
        if (prev == '1') { prev = pila[idx].top(); pila[idx].pop(); }

        if (pila[idx].empty())
            pila[1 - idx].push(prev);
        else {
            char b = pila[idx].top(); pila[idx].pop();

            if (prev != b)
                count = true;
            else
                pila[1 - idx].push(prev);

            prev = b;
        }
    }

    if (!count) break;
    ans++;
}
