const CppTurbo = require('./NativeCppTurbo').default;

export function multiply(a: number, b: number): number {
  return CppTurbo.multiply(a, b);
}
