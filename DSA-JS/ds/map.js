const map = new Map([
  ["a", 1],
  ["b", 2],
]);

map.set("c", 3);
map.has("a");
map.delete("c");
map.size;
map.clear();

for (const [key, value] of map) {
  console.log(`${key}: ${value}`);
}
