use std::io::BufRead;

fn input() -> String {
    std::io::stdin().lock().lines().next().unwrap().unwrap()
}

fn func(
    memo: &mut Vec<Vec<usize>>,
    obj: &mut Vec<Vec<usize>>,
    item_count: usize,
    max_weight: usize,
) -> usize {
    for i in 1..item_count + 1 {
        for j in 1..max_weight + 1 {
            if obj[i][0] > j {
                memo[i][j] = memo[i - 1][j];
            } else {
                let a = memo[i - 1][j];
                let b = obj[i][1] + memo[i - 1][j - obj[i][0]];
                if a > b {
                    memo[i][j] = a;
                } else {
                    memo[i][j] = b;
                }
            }
        }
    }

    return memo[item_count][max_weight];
}

fn main() {
    let nk: Vec<usize> = input()
        .split_ascii_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let n = nk[0];
    let k = nk[1];

    let mut memo: Vec<Vec<usize>> = vec![vec![0; 100001]; 101];
    let mut object: Vec<Vec<usize>> = vec![vec![0; 2]; 101];

    for i in 1..n + 1 {
        let tmp: Vec<usize> = input()
            .split_ascii_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();

        object[i][0] = tmp[0];
        object[i][1] = tmp[1];
    }

    println!("{}", func(&mut memo, &mut object, n, k));
}
