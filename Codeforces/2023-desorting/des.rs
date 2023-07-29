
#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};

#[allow(dead_code)]
struct ObiWan {
    input_buffer: Vec<String>,
    output_buffer: BufWriter::<std::io::Stdout>
}
impl ObiWan {
    #[allow(dead_code)]
    fn new() -> Self {
        ObiWan {
            input_buffer: vec![],
            output_buffer: BufWriter::new(stdout())
        }
    }
    #[allow(dead_code)]
    fn read<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.input_buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.input_buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
    #[allow(dead_code)]
    fn write<T: std::fmt::Display>(&mut self, s: T) {
        write!(&mut self.output_buffer, "{}", s).ok();
    }
    #[allow(dead_code)]
    fn flush(&mut self) {
        self.output_buffer.flush().ok();
    }
}

fn main() {
    const N:usize = 510;

    let mut obiwan = ObiWan::new();
    let t = obiwan.read();
    for _ in 0..t {
        let n = obiwan.read();
        let mut a = [0i32; N];
        for i in 1..=n { a[i] = obiwan.read(); }
        
        let mut ans = i32::MAX;
        for i in 1..=(n-1) {
            ans = min(ans, a[i+1] - a[i]);
        }
        ans = if ans < 0 { 0 } else { 1 + ans / 2 };

        obiwan.write(ans);
        obiwan.write('\n');
    }   
}