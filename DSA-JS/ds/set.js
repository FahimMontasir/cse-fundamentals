const set = new Set([1, 2, 3]);

set.add(4);
set.has(4);
set.delete(3);
set.size;
set.clear();

for (const item of set) {
  console.log(item);
}
