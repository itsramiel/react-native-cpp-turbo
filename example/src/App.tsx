import { StyleSheet, View, Button } from 'react-native';
import {
  reverseString,
  promiseNumber,
  callMeLater,
  getNumbers,
  getOBject,
} from 'react-native-cpp-turbo';

export default function App() {
  return (
    <View style={styles.container}>
      <Button
        title="reverse string"
        onPress={() => {
          console.log(reverseString('reverse string'));
        }}
      />
      <Button
        title="get number"
        onPress={() => {
          console.log(getNumbers());
        }}
      />
      <Button
        title="get object"
        onPress={() => {
          console.log(getOBject());
        }}
      />
      <Button
        title="promise"
        onPress={async () => {
          const value = await promiseNumber(5);

          console.log('promised value is: ', value);
        }}
      />
      <Button
        title="callbacks"
        onPress={() => {
          callMeLater(
            () => console.log('success'),
            () => console.log('failure')
          );
        }}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    gap: 8,
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
