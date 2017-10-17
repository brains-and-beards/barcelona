open ReactNative;

module Style = {
  open ReactNative.Style;
  let container =
    style [
      height 85.,
      borderTopWidth 20.,
      borderTopColor Colors.black,
      backgroundColor Colors.brainsYellow,
      alignItems `flexStart,
      justifyContent `center
    ];
  let title =
    style [
      textAlign `left,
      textAlignVertical `center,
      fontSize 20.,
      fontFamily "Poppins",
      paddingLeft 20.
    ];
};

let component = ReasonReact.statelessComponent "NavBar";

let make _children => {
  ...component,
  render: fun _self => {
    StatusBar.setBarStyle `lightContent ();
    <View style=Style.container> <Text style=Style.title value="Recommendations" /> </View>
  }
};
