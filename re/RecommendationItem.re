open ReactNative;

module Style = {
  open ReactNative.Style;
  let content = style [flex 1., paddingTop 15., paddingHorizontal 25., marginBottom 25.];
  let container =
    style [
      backgroundColor Colors.white,
      height 325.,
      shadowOpacity 0.3,
      shadowRadius 3.,
      shadowOffset height::3. width::0.,
      marginBottom 10.
    ];
  let image = style [height 200., width (float_of_int Theme.width)];
  let title =
    style [alignItems `flexStart, justifyContent `center, fontSize 26., fontWeight `_600];
  let description = style [height 65., fontSize 14.];
};

let component = ReasonReact.statelessComponent "RecommendationItem";

let make place::(place: Recommendation.place) _children => {
  ...component,
  render: fun _self =>
    <View style=Style.container>
      <Image source=place.image resizeMode=`cover style=Style.image />
      <View style=Style.content>
        <CustomText style=Style.title> place.title </CustomText>
        <CustomText style=Style.description> place.description </CustomText>
      </View>
    </View>
};
