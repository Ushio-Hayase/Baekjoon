use std::io::{stdout, BufRead, BufWriter, Write};

fn input() -> String {
    std::io::stdin().lock().lines().next().unwrap().unwrap()
}

fn main() {
    let nm: Vec<usize> = input()
        .split_ascii_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    let n = nm[0];
    let m = nm[1];

    let mut writer = BufWriter::new(stdout());

    let mut table: Vec<Vec<u64>> = vec![vec![0; n]; n];
    for i in 0..n {
        let tmp_list: Vec<u64> = input()
            .split_ascii_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();

        for j in 0..n {
            if i == 0 && j == 0 {
                table[i][j] = tmp_list[j];
            } else if i != 0 && j == 0 {
                table[i][j] = table[i - 1][j] + tmp_list[j];
            } else if i == 0 && j != 0 {
                table[i][j] = table[i][j - 1] + tmp_list[j];
            } else {
                table[i][j] = table[i][j - 1] + table[i - 1][j] - table[i - 1][j - 1] + tmp_list[j];
            }
        }
    }

    for _ in 0..m {
        let tmp_list: Vec<usize> = input()
            .split_ascii_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();

        let (y1, x1, y2, x2) = (
            tmp_list[0] - 1,
            tmp_list[1] - 1,
            tmp_list[2] - 1,
            tmp_list[3] - 1,
        );

        if x1 == 0 && y1 == 0 {
            writeln!(writer, "{}", table[y2][x2]).unwrap();
        } else if x1 == 0 && y1 != 0 {
            writeln!(writer, "{}", table[y2][x2] - table[y1 - 1][x2]).unwrap();
        } else if x1 != 0 && y1 == 0 {
            writeln!(writer, "{}", table[y2][x2] - table[y2][x1 - 1]).unwrap();
        } else {
            let res = table[y2][x2] + table[y1 - 1][x1 - 1] - table[y2][x1 - 1] - table[y1 - 1][x2];

            writeln!(writer, "{}", res).unwrap();
        }
    }
}
