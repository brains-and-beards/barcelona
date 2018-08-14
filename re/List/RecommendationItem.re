open BsReactNative;

module Style = {
  open BsReactNative.Style;
  let content =
    style([
      flex(1.),
      paddingTop(Pt(15.)),
      paddingHorizontal(Pt(25.)),
      marginBottom(Pt(25.)),
    ]);
  let container =
    style([
      backgroundColor(Colors.white),
      height(Pt(325.)),
      shadowOpacity(0.3),
      shadowRadius(3.),
      shadowOffset(~height=3., ~width=0.),
      marginBottom(Pt(10.)),
    ]);
  let image =
    style([height(Pt(200.)), width(Pt(float_of_int(Theme.width)))]);
  let title =
    style([
      alignItems(FlexStart),
      justifyContent(Center),
      fontSize(Float(26.)),
      fontWeight(`_600),
    ]);
  let description = style([height(Pt(65.)), fontSize(Float(14.))]);
};

let component = ReasonReact.statelessComponent("RecommendationItem");

let make = (~place: Recommendation.place, ~openDetails, _children) => {
  ...component,
  render: _self =>
    <TouchableOpacity
      style=Style.container
      onPress=(
        () => {
          openDetails(place.uuid);
          ();
        }
      )>
      <Image source=place.image resizeMode=`cover style=Style.image />
      <View style=Style.content>
        <CustomText style=Style.title> place.title </CustomText>
        <CustomText style=Style.description> place.description </CustomText>
      </View>
    </TouchableOpacity>,
};