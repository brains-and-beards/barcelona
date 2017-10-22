open ReactNative;

module Style = {
  open ReactNative.Style;
  let container = style [flex 1., backgroundColor Colors.white];
  let categories =
    style [
      height 60.,
      backgroundColor Colors.white,
      paddingHorizontal 80.,
      flexDirection `row,
      justifyContent `spaceBetween,
      alignItems `center
    ];
};

type state = {filter: Category.filter};

type action =
  | ChangeFilter Category.filter;

let component = ReasonReact.reducerComponent "RecommendationList";

let make _children => {
  ...component,
  initialState: fun () => {filter: Category.Category Eat},
  reducer: fun action state =>
    switch action {
    | ChangeFilter filter => ReasonReact.Update {...state, filter}
    },
  render: fun self => {
    let recommendations =
      Array.mapi
        (
          fun index place =>
            <RecommendationItem key=("recommendation-" ^ string_of_int index) place />
        )
        Recommendation.recommendations;
    let currentFilter = self.state.filter;
    <ScrollView style=Style.container>
      <NavBar />
      <View style=Style.categories>
        <Category filterCategory=All currentFilter />
        <Category filterCategory=(Category See) currentFilter />
        <Category filterCategory=(Category Eat) currentFilter />
      </View>
      (ReasonReact.arrayToElement recommendations)
    </ScrollView>
  }
};
