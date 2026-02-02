vector<ll> getDivisors(const map<ll, int>& f) {
    vector<ll> divisors = { 1 };
    for (auto [p, e] : f) {
        vector<ll> next;
        ll pe = 1;
        for (int i = 0; i <= e; i++) {
            for (ll d : divisors)
                next.push_back(d * pe);
            pe *= p;
        }
        divisors.swap(next);
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}
