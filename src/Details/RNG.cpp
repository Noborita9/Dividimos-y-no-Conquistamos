using my_clock = chrono::steady_clock;
struct Random {
	mt19937_64 engine;
	Random(): engine(my_clock::now().time_since_epoch().count()) {}
	template<class Int>Int integer(Int n) {return integer<Int>(0, n);} // `[0,n)`
	template<class Int>Int integer(Int l, Int r)
		{return uniform_int_distribution{l, r-1}(engine);} // `[l,r)`
	double real() {return uniform_real_distribution{}(engine);} // `[0,1)`
} rng;