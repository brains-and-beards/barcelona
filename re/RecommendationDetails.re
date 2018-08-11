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

let make = (~placeID, _children) => {
  ...component,
  render: _self => {
    let place = Recommendation.find(placeID);
    <ScrollView style=Style.container>
      <Text value=place.title />
    </ScrollView>;
  },
};