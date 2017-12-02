open ReactNative;

module Style = {
  open ReactNative.Style;
  let container =
    style([
      height(60.),
      backgroundColor(Colors.brainsYellow),
      alignItems(`flexStart),
      justifyContent(`center)
    ]);
  let title =
    style([
      textAlign(`left),
      textAlignVertical(`center),
      fontSize(20.),
      fontFamily("Poppins"),
      paddingLeft(20.)
    ]);
};

let component = ReasonReact.statelessComponent("NavBar");

let make = (_children) => {
  ...component,
  render: (_self) => {
    StatusBar.setBarStyle(`lightContent, ());
    <View style=Style.container> <Text style=Style.title value="Recommendations" /> </View>
  }
};