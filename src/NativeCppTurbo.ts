import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  reverseString: (str: string) => string;

  getNumbers: () => Array<number>;

  getOBject: () => { [key: string]: string };

  promiseNumber: (value: number) => Promise<number>;

  callMeLater: (successCB: () => void, failureCB: () => void) => void;
}

export default TurboModuleRegistry.getEnforcing<Spec>('CppTurbo');
