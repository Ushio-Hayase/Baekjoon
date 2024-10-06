// 첫번째 인덱스 : before_idx, 두번째 인덱스: left_count,
// 세번째 인덱스: final_idx, 들어있는 값: 해당하는 상태의 경우의 수
static mut DP: Vec<Vec<Vec<usize>>> = Vec::new();

fn input() -> String {
    std::io::stdin().lines().next().unwrap().unwrap()
}

fn build(before_idx: i32, left_count: usize, final_idx: usize) -> usize {
    if left_count == 0 {
        return 1;
    }

    if before_idx >= 0 {
        let dp: usize = unsafe { DP[before_idx as usize][left_count][final_idx] };
        if dp != 0 {
            return dp;
        }
    }
    let available_last_idx = final_idx - left_count;
    let mut res: usize = 0;

    for i in before_idx + 1..available_last_idx as i32 + 1 {
        res += build(i, left_count - 1, final_idx);
    }
    if before_idx >= 0 {
        unsafe {
            DP[before_idx as usize][left_count][final_idx] = res;
        }
    }
    res
}

fn main() {
    let t: usize = input().trim().parse().unwrap();

    for _ in 0..t {
        let sight: Vec<usize> = input()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        unsafe { DP = vec![vec![vec![0; sight[1] + 1]; sight[0] + 1]; sight[1] + 1] }
        println!("{}", build(-1, sight[0], sight[1]));
    }
}
