import React from 'react';
import { Image, Pressable, View } from 'react-native';
import { viewStyles } from './styles';

const styles = viewStyles();

type Props = {
  iconUrl: string;
  bgUrl?: string;
  changeRoute?: () => void;
};

const Tile = (props: Props) => {
  if (props?.bgUrl != null)
    return (
      <View style={styles.tileContainer}>
        <View style={styles.tileBackground}>
          <Image style={styles.bgImage} resizeMode="cover" source={{ uri: props?.bgUrl }} />
        </View>
        <Image style={styles.icon} source={{ uri: props.iconUrl }} />
      </View>
    );
  else if (props?.changeRoute)
    return (
      <Pressable onPress={props?.changeRoute} style={styles.tileContainer}>
        <Image style={styles.iconOnly} resizeMode="center" source={{ uri: props.iconUrl }} />
      </Pressable>
    );
  else
    return (
      <View style={styles.tileContainer}>
        <Image style={styles.iconOnly} resizeMode="center" source={{ uri: props.iconUrl }} />
      </View>
    );
};

export default Tile;
