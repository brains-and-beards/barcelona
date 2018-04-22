open BsReactNative;

module Style = {
  open BsReactNative.Style;
  let container =
    style([
      height(Pt(60.)),
      backgroundColor(Colors.brainsYellow),
      alignItems(FlexStart),
      justifyContent(Center)
    ]);
  let title =
    style([
      textAlign(Left),
      textAlignVertical(Center),
      fontSize(Float(20.)),
      fontFamily("Poppins"),
      paddingLeft(Pt(20.))
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