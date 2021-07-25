import { StyleSheet } from 'react-native';

export const viewStyles = () => {
  return StyleSheet.create({
    tileContainer: {
      width: '25%',
      alignItems: 'center',
      justifyContent: 'flex-end',
      aspectRatio: 9 / 16,
    },
    tileBackground: {
      position: 'absolute',
      top: 0,
      bottom: 0,
      left: 0,
      right: 0,
    },
    bgImage: {
      flex: 1,
      flexDirection: 'column',
    },
    icon: {
      aspectRatio: 1,
      width: '25%',
      height: '25%',
    },
    iconOnly: {
      width: '100%',
      height: '100%',
    },
  });
};
