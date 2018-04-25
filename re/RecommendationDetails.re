open BsReactNative;

module Style = {
  open BsReactNative.Style;
  let container = style([flex(1.), backgroundColor(Colors.white)]);
  let categories =
    style([
      height(Pt(60.)),
      backgroundColor(Colors.white),
      paddingHorizontal(Pt(80.)),
      flexDirection(Row),
      justifyContent(SpaceBetween),
      alignItems(Center),
    ]);
};

let component = ReasonReact.statelessComponent("RecommendationDetails");

let make = _children => {
  ...component,
  render: _self => <ScrollView style=Style.container> <NavBar /> </ScrollView>,
};