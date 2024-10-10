use std::io::Error;

static mut ARR: Vec<usize> = Vec::new();
static mut DP: Vec<usize> = Vec::new();

fn input() -> String {
    std::io::stdin().lines().next().unwrap().unwrap()
}

fn search(index: usize, before_elem: usize) -> usize {
    if unsafe { DP[index] } != 0 {
        return unsafe { DP[index] };
    }

    let now_elem = unsafe { ARR[index] };

    if now_elem <= before_elem {
        return 0;
    }

    let mut res = now_elem;

    for i in index + 1..unsafe { ARR.len() } {
        let tmp = search(i, now_elem) + now_elem;

        if res < tmp {
            res = tmp;
        }
    }

    unsafe {
        DP[index] = res;
    }
    res
}

fn main() {
    unsafe {
        let dp_len: usize = input().parse().unwrap();
        ARR = input()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        DP = vec![0; dp_len];
    }

    let mut res = 0;

    for i in 0..unsafe { ARR.len() } {
        let tmp = search(i, 0);
        if res < tmp {
            res = tmp;
        }
    }

    println!("{res}");
}
