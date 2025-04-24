import OpenAI from "https://deno.land/x";
function capitalize(word: string): string {
  return word.charAt(0).toUpperCase() + word.slice(1);
}

function greet(name: string): string {
  return "Hello " + capitalize(name);
}

console.log(greet("venkatesh"));
console.log(greet("jimmy"));
