open ReactNative;

module Style = {
  open ReactNative.Style;
  let container =
    style [
      height 85.,
      borderTopWidth 25.,
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
  render: fun _self =>
    <View style=Style.container> <Text style=Style.title value="Recommendations" /> </View>
};
