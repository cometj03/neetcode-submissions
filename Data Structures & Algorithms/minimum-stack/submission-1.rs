struct MinStack {
    minStack: Vec<i32>,
    stack: Vec<i32>
}

impl MinStack {
    pub fn new() -> Self {
        MinStack {
            minStack: vec![],
            stack: vec![]
        }
    }

    pub fn push(&mut self, val: i32) {
        match self.minStack.last() {
            None => self.minStack.push(val),
            Some(&n) if n >= val => self.minStack.push(val),
            _ => ()
        }
        self.stack.push(val);
    }

    pub fn pop(&mut self) {
        if self.stack.pop() == self.minStack.last().copied() {
            self.minStack.pop();
        }
    }

    pub fn top(&self) -> i32 {
        match self.stack.last() {
            Some(&n) => n,
            None => -1
        }
    }

    pub fn get_min(&self) -> i32 {
        match self.minStack.last() {
            Some(&n) => n,
            None => -1
        }
    }
}
