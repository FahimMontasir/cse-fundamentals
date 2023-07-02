const obj = {
  name: "bruce",
  age: 25,
  "key-three": true,
  sayMyNme: function () {
    console.log(this.name);
  },
};

obj.hobby = "football"; // O(1)

delete obj.hobby; // O(1)

obj.name; // O(1)
obj["key-three"]; // O(1)

// O(n) learn more method eg. Object.keys(), .values(), .entries()
