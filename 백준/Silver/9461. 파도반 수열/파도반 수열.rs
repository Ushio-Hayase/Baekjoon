static mut DP: Vec<usize> = Vec::new();
fn input() -> String {
    std::io::stdin().lines().next().unwrap().unwrap()
}

fn func(x: usize) -> usize {
    if unsafe { DP[x] } != 0 {
        unsafe {
            return DP[x];
        };
    }

    unsafe {
        DP[x] = func(x - 1) + func(x - 5);
        return DP[x];
    }
}

fn main() {
    let t: usize = input().trim().parse().unwrap();

    unsafe {
        DP = vec![0; 101];
        DP[1] = 1;
        DP[2] = 1;
        DP[3] = 1;
        DP[4] = 2;
        DP[5] = 2;
    }

    for _ in 0..t {
        let x: usize = input().parse().unwrap();

        println!("{}", func(x));
    }
}
