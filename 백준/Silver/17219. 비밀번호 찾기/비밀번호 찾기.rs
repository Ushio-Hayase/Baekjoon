use std::{collections::HashMap, hash::Hash, io::BufRead};

fn input() -> String {
    std::io::stdin()
        .lines()
        .next()
        .unwrap()
        .unwrap()
        .trim()
        .to_string()
}

fn main() {
    let mut hashmap: HashMap<String, String> = HashMap::new();
    let a: Vec<i32> = input()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    for _ in 0..a[0] {
        let tmp: Vec<String> = input().split_whitespace().map(|x| x.to_string()).collect();
        hashmap.insert(tmp[0].to_string(), tmp[1].to_string());
    }

    for _ in 0..a[1] {
        let key = input();
        println!("{}", hashmap.get(&key).unwrap());
    }
}
